#include <algorithm>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <vector>

namespace handt {

// The container passed throughout
using cont = const std::vector<double> &;

// Function definitions for the strategy types
using func1 = std::function<bool(cont)>;
using func2 = std::function<double(cont)>;

// Primary strategies are simple boolean tests
const std::vector<std::pair<std::string, func1>> primary_strategies{
    // Always return positively
    {"crouching",
     [](cont p) {
       static_cast<void>(p);
       return true;
     }},

    // Return positively if trending upwards
    {"leaping",
     [](cont p) {
       unsigned int trend = 0;
       for (auto i = p.cbegin(); i != std::prev(p.cend()); ++i)
         if (*i < *std::next(i))
           ++trend;

       return trend > p.size() / 2;
     }},

    // Return positively if trending downwards
    {"supine",
     [](cont p) {
       unsigned int trend = 0;
       for (auto i = p.cbegin(); i != std::prev(p.cend()); ++i)
         if (*i > *std::next(i))
           ++trend;

       return trend > p.size() / 2;
     }},

    // Return positively if crossing a significant boundary
    {"straddling",
     [](cont p) {
       const auto &[min, max] = std::minmax(p.front(), p.back());

       unsigned long threshold = 0;
       for (const unsigned long &mod : {1, 10, 100, 1000, 10000}) {

         const unsigned long test =
             max - (static_cast<unsigned long>(max) % mod);

         if (test == 0)
           break;

         threshold = test;
       }

       return min < threshold && max > threshold;
     }},
};

// Strategy definition helper routines
const auto mean = [](const std::vector<double> &p) {
  return std::accumulate(p.cbegin(), p.cend(), 0.0) / double(p.size());
};

const auto maximum = [](const auto &p) {
  return *std::max_element(p.cbegin(), p.cend());
};

const auto minimum = [](const auto &p) {
  return *std::min_element(p.cbegin(), p.cend());
};

const auto not_front = [](const auto &p) {
  return std::vector<double>{std::next(p.cbegin()), p.cend()};
};

const auto back_end = [](const auto &p) {
  return std::vector<double>{std::next(p.cbegin(), p.size() / 2), p.cend()};
};

const auto front_end = [](const auto &p) {
  return std::vector<double>{p.cbegin(), std::prev(p.cend(), p.size() / 2)};
};

const auto not_back = [](const auto &p) {
  return std::vector<double>{p.cbegin(), std::prev(p.cend())};
};

const auto front = [](const auto &p) { return p.front(); };
const auto back = [](const auto &p) { return p.back(); };

// Secondary strategies yield a buy threshold
const std::vector<std::pair<std::string, func2>> secondary_strategies{

    // Always succeed
    {"lundehund",
     [](cont p) {
       static_cast<void>(p);
       return 2.0;
     }},

    // front/back
    {"norrbottenspets", [](cont p) { return front(p) / back(p); }},
    {"jagdterrier", [](cont p) { return back(p) / front(p); }},

    // mean over front/back
    {"xoloitzcuintli", [](cont p) { return mean(p) / back(p); }},
    {"basenji", [](cont p) { return mean(p) / front(p); }},
    {"owl", [](cont p) { return front(p) / mean(p); }},
    {"affenpinscher", [](cont p) { return back(p) / mean(p); }},

    // partial means
    {"capybara", [](cont p) { return mean(front_end(p)) / mean(back_end(p)); }},
    {"munchkin", [](cont p) { return mean(back_end(p)) / mean(front_end(p)); }},
    {"badger", [](cont p) { return mean(p) / mean(back_end(p)); }},
    {"bandicoot", [](cont p) { return mean(back_end(p)) / mean(p); }},

    // min/max over back/front
    {"mink", [](cont p) { return minimum(not_back(p)) / back(p); }},
    {"ocelot", [](cont p) { return minimum(not_front(p)) / front(p); }},
    {"griffon", [](cont p) { return maximum(not_back(p)) / back(p); }},
    {"cricket", [](cont p) { return maximum(not_front(p)) / front(p); }},

    // back/front over min/max
    {"axolotl", [](cont p) { return back(p) / minimum(not_back(p)); }},
    {"tiger", [](cont p) { return front(p) / minimum(not_front(p)); }},
    {"caddisfly", [](cont p) { return back(p) / maximum(front_end(p)); }},
    {"narwahl", [](cont p) { return front(p) / maximum(not_front(p)); }},
};

} // namespace handt

int main() {

  // Create a set of thresholds to use with each buy strategy
  std::vector<int> thresholds(20);
  std::iota(thresholds.begin(), thresholds.end(), 2);

  // A complete strategy consists of a primary and secondary strategy and a buy
  // threshold
  struct strategy_combo {
    std::string name;
    handt::func1 primary;
    handt::func2 secondary;
    int threshold;
  };

  // Create and initialise a container for all strategy and threshold
  // permuations
  std::vector<strategy_combo> permutations;
  const auto total_permutations = handt::primary_strategies.size() *
                                  handt::secondary_strategies.size() *
                                  thresholds.size();
  permutations.reserve(total_permutations);

  // Populate with strategies from the handt library
  for (const auto &[name1, buy1] : handt::primary_strategies)
    for (const auto &[name2, buy2] : handt::secondary_strategies)
      for (const auto &threshold : thresholds)
        permutations.push_back(
            {name1 + ' ' + name2 + ' ' + std::to_string(threshold), buy1, buy2,
             threshold});

  // The sell strategy returns positively if the expected yield is acheived
  // within the trading window
  const auto sell = [](const auto &current, const auto &future) {
    return std::find_if(
        current, future,
        [spot = *current, threshold = 1.05](const auto &future_price) {
          return future_price > spot * threshold;
        });
  };

  // Fetch list of price files
  std::vector<std::string> currency_pairs;
  for (const auto &file : std::filesystem::directory_iterator("tmp"))
    currency_pairs.emplace_back(file.path());

  // Structure to capture the results during a strategy back test
  struct strategy_performance {
    std::string name;
    std::string from_symbol;
    std::string to_symbol;
    std::string exchange;
    double spot = 0.0;
    unsigned int good_deals = 0;
    unsigned int bad_deals = 0;
    bool buy = false;
  };

  // Create container for final strategy report
  std::list<strategy_performance> performance;

  // Extract prices from each file
  for (const auto &file : currency_pairs) {

    // Open prices and get the trade info
    std::ifstream in(file);
    std::string from_symbol, to_symbol, exchange;
    in >> from_symbol >> to_symbol >> exchange;

    // Get the prices and run the strategies over them
    const std::vector<double> prices{std::istream_iterator<double>(in), {}};

    // Check read has succeeded and execute strategies
    if (!prices.empty())
      for (const auto &strat : permutations) {

        // Create a new strategy and add it to the summary for later
        const auto spot = prices.back();
        auto &perf = performance.emplace_back(strategy_performance{
            strat.name, from_symbol, to_symbol, exchange, spot});

        // Configure trading periods for back test
        const unsigned int analysis_window = 24;
        const unsigned int sell_window = analysis_window * 2;

        // Set up some indices into the prices. Historic price is the first
        // price in the analysis window and the future price is the furthest
        // price after the current price that we're prepared to trade. e.g.,
        // 24-hour analysis window and 48-hour trade window

        // |-- analysis window --|
        // H--------------------NOW-----------------F
        //                       |-- trade window --|

        // Initialise the price markers to the start of historic price data
        auto historic_price_index = prices.cbegin();
        auto current_price_index =
            std::next(historic_price_index, analysis_window);
        auto future_price_index = std::next(current_price_index, sell_window);

        // Calculate the buy ratio
        const double ratio = (100.0 + strat.threshold) / 100;

        // Move windows along until we run out of prices
        while (future_price_index < prices.cend()) {

          // Test strategy
          if (strat.primary({historic_price_index, current_price_index}) &&
              strat.secondary({historic_price_index, current_price_index}) >
                  ratio) {

            // Strategy triggered, so look ahead to see if it succeeded in
            // the defined trade window
            if (const auto sell_price_index =
                    sell(current_price_index, future_price_index);
                sell_price_index != future_price_index) {
              ++perf.good_deals;

              // Move the analysis window so the next iteration starts at
              // the last sell price
              historic_price_index = sell_price_index;
            } else
              ++perf.bad_deals;
          }

          // Nudge the analysis window along and update upstream prices
          std::advance(historic_price_index, 1);
          current_price_index =
              std::next(historic_price_index, analysis_window);
          future_price_index = std::next(current_price_index, sell_window);
        }

        // Calculate prospects using the most recent prices
        historic_price_index = std::prev(prices.cend(), analysis_window);
        current_price_index = prices.cend();

        // Test the latest prices
        if (strat.primary({historic_price_index, current_price_index}) &&
            strat.secondary({historic_price_index, current_price_index}) >
                ratio)
          perf.buy = true;
      }
  }

  // Sort strategies by performance
  performance.sort([](const auto &a, const auto &b) {
    return (a.good_deals ? a.good_deals : 1.0) /
               (a.bad_deals ? a.bad_deals : 1.0) >
           (b.good_deals ? b.good_deals : 1.0) /
               (b.bad_deals ? b.bad_deals : 1.0);
  });

  // Pretty print large numbers
  std::cout.imbue(std::locale(""));

  // Strategy and trade overview
  std::cout << currency_pairs.size() << " currency pairs, "
            << handt::primary_strategies.size() << " primary strategies, "
            << handt::secondary_strategies.size() << " secondary strategies, "
            << thresholds.size() << " thresholds, (" << permutations.size()
            << " strategy permutations), " << performance.size()
            << " tests performed.\n\n";

  // Report individual strategy performance
  std::cout << "Strategy|Pair|Good/Bad|Spot|Advice\n";
  std::cout << "---|---|---|---|---\n";
  for (const auto &s : performance)
    std::cout << s.name << '|' << '[' << s.from_symbol << ' ' << s.to_symbol <<

        "]("
              << (s.exchange == std::string("Coinbase")
                      ? "https://coinbase.com"
                      : s.exchange == std::string("Binance")
                            ? "https://www.binance.com/en/trade/" +
                                  s.from_symbol + '_' + s.to_symbol
                            : "no_url")
              << ')' << '|' << s.good_deals << '/' << s.bad_deals << '|'
              << s.spot << '|' << (s.buy ? "BUY! <!-- ****** -->" : "") << '\n';
}
