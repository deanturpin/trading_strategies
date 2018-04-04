#include "handt.h"
#include <algorithm>
#include <vector>
#include <iostream>

int main() {

  // Get all review positions
  const auto &reviewed_positions = handt::get_reviewed_positions();

  // Read current balance
  const std::string filename("balance.csv");
  std::ifstream file(filename);
  double balance = 1000000.0;
  if (file.good())
    file >> balance;
  file.close();

  const double trade_size = 1000.0;

  // Update balance for each position
  for (const auto &position : reviewed_positions)
    if (!position.open)
      balance += trade_size * position.yield() - trade_size;
    else
      if (position.status == "NEWTRADE")
        balance -= trade_size;

  std::cout << balance << '\n';

  // Write the updateed balance back
  std::ofstream file_out(filename);
  if (file_out.good())
    file_out << balance;
}
