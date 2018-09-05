#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

// A currency pair is a duo of symbols and an exchange whence the price came
struct currency_pair {
  std::string from_sym{};
  std::string to_sym{};
  std::string exchange{};
};

std::vector<currency_pair> get_pairs() {

  currency_pair p;

  // Extract and store the portfolio of currency pairs
  std::vector<currency_pair> pairs;
  std::ifstream in("pairs2.csv");
  while (in >> p.from_sym >> p.to_sym >> p.exchange)
    pairs.emplace_back(p);

  return pairs;
}

int main() {

  // Fetch the pairs we're interested in
  const auto &pairs = get_pairs();
  std::cout << pairs.size() << " pairs read\n";

  // Get prices
  for (auto &file : std::filesystem::directory_iterator("tmp")) {

    // Get the trade params
    std::ifstream in(file.path());
    if (currency_pair p; in >> p.from_sym >> p.to_sym >> p.exchange)
      std::cout << p.from_sym << " processing\n";

    // Get the prices
    const std::vector<double> prices{std::istream_iterator<double>(in), {}};

    std::cout << prices.size() << " prices read\n";

    // Backtest
    std::cout << std::accumulate(prices.cbegin(), prices.cend(), 0.0) /
                     prices.size()
              << " average price\n";

    // Configure trading period
    const unsigned int test_period = 200;
    const unsigned int look_ahead = test_period * 2;

    // Set up some indices into the prices
    auto begin = prices.cbegin();
    auto end = std::next(begin, test_period);
    auto until = std::next(end, look_ahead);

    while (until < prices.cend()) {
      std::cout << std::distance(prices.cbegin(), begin) << '\t'
                << (*begin > *end && *std::max_element(end, until) > *end * 1.05
                        ? "buy"
                        : "sell")
                << '\n';

      std::advance(begin, test_period);
      end = 			std::next(begin, test_period);
      until = std::next(end, look_ahead);


    }
  }
}
