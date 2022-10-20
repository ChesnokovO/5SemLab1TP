#include <iostream>
#include "Figures.h"

using namespace std;

Figures::Figures(){
  std::cout << "Constuctor Figures without parametrs" << "\n";
};

Figures::~Figures(){
  std::cout << "Destructor Figure" << "\n";
};

void Figures::checkCondition(bool condition, std::string message) {
  if (condition) throw std::runtime_error(message);
}