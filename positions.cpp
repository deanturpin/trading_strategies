#include <fstream>
#include <iomanip>
#include <chrono>
#include <istream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <vector>
#include <map>
#include "strategy.h"

std::map<std::string, std::vector<double>> get_prices();

// Struggled for a while how to handle a no position. Zero is the first choice
// but zero also represents a complete fail. Perhaps that also represents a no
// position?
struct position {

  // These are set by initialiser
  std::string name = "name";
  std::string buy_price = "buy_price";
  std::string buy_time = "buy_time";
  std::string strategy = "strategy";

  // These are defaulted
  std::string sell_time = "sell_time";
  std::string sell_price = "sell_price";
  std::string yield = "yield";
  std::string duration = "duration";

  friend std::ostream& operator<< (std::ostream& os, const position& p) {
    return os
      << p.name << " "
      << p.buy_time << " "
      << p.sell_time << " "
      << p.duration << " "
      << p.buy_price << " "
      << p.sell_price << " "
      << p.yield << " "
      << p.strategy;
  }
};

// Create a timestamp
std::string timestamp();
int main() {

  // Get some recent prices
  auto prices = get_prices();

  // Create a strategy
  always s;

  std::vector<position> positions;

  // Test strategy on each coin
  for (const auto &coin : prices) {

    const std::string name = coin.first;
    const double spot = coin.second.back();

    const double position = 100000.1;

    // Do we buy?
    if (s.buy(coin.second)) {
      struct position pos({name, std::to_string(spot), timestamp(), s.name});
      positions.push_back(pos);
    }

    // Or do we... sell?
    // else if (s.sell(position, spot))
      // std::cout << "\tsell\n";
  }

  // Write out positions
  for (const auto & p : positions)
    std::cout << p << "\n";
}

// Get prices and return a container full of them
std::map<std::string, std::vector<double>> get_prices() {
  std::map<std::string, std::vector<double>> prices;

  // Read some prices
  std::ifstream in("prices.csv");
  if (in.good()) {

    // The first item is the coin name
    std::string coin;
    while (in >> coin) {

      // The remainder of the line contains values
      std::string line;
      std::getline(in, line);
      std::stringstream ss(line);

      // Extract values into a container
      std::vector<double> p;
      copy(std::istream_iterator<double>(ss), std::istream_iterator<double>(),
           std::back_inserter(p));

      prices.insert(std::make_pair(coin, p));
    }
  }

  return prices;
}

// Turn right now into a string timestamp
std::string timestamp() {

  // Get now
  using namespace std::chrono;
  using clock = std::chrono::system_clock;
  const auto now = clock::now();

  // Create a date string
  const auto in_time_t = clock::to_time_t(now);
  std::stringstream date;
  date << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d-%X");

  return date.str();
}

