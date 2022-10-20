#include <iostream>
#include <limits>

template <typename T> T input() {
  T value;
  std::cin >> value;
  while (true) {
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << std::endl << "You have entered wrong input" << std::endl;
      std::cin >> value;
    }
    if(!std::cin.fail()) break;
  }
  return value;
}