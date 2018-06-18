#ifndef HANDT_H
#define HANDT_H

#include <chrono>
#include <fstream>
#include <iomanip>
#include <istream>
#include <iterator>
#include <map>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

namespace handt {

// A prospect has a name, a spot price and a list of strategies that
// triggered the prospect
struct prospect {
  std::string symbol{};
  double spot{};
  std::vector<std::string> strategies{};

  friend std::istream &operator>>(std::istream &is, prospect &p) {
    is >> p.symbol >> p.spot;
    p.strategies = {std::istream_iterator<std::string>(is), {}};
    return is;
  }
};

// A coin is a currency pair and a series of prices
struct coin {
  std::string from_symbol{"no symbol"};
  std::string to_symbol{"no symbol"};
  std::string exchange{"no exchange"};
  std::vector<double> series{};

  friend std::istream &operator>>(std::istream &is, coin &p) {
    is >> p.from_symbol >> p.to_symbol >> p.exchange;
    p.series = {std::istream_iterator<double>(is), {}};
    return is;
  }
};

// Generic routine to extract a series of objects from a file and populate a
// container
template <typename Object> auto get_objects(const std::string &file) {

  // Declare object to be returned
  std::vector<Object> objects;

  // Step through each line extracting the object and pushing onto a container,
  // unless the line starts with a comment character then skip it
  std::ifstream in(file);
  std::string line;
  while (getline(in, line))
    if (line.front() != '#') {
      std::stringstream ss(line);
      Object p;
      ss >> p;
      objects.push_back(p);
    }

  // Return the extracted objects
  return objects;
}

// Wrappers to parse files and return containers of various objects
auto get_prices() { return get_objects<coin>("prices.csv"); }
auto get_pairs() { return get_objects<std::string>("pairs.csv"); }
}

#endif
