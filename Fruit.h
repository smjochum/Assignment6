//============================================================================
// File Name   : Fruit.h
// Author      : Sarah Jochum
// Copyright   : 2021 copyright
// Description :  A class that represents a fruit within a supermarket.

// Disclaimer: Google Coding style. 4 space instead of tab and 2 space indent.
// Revision History:
// Date              Version     Change ID         Author             Comment
// 12-06-21          1.0           001             Sarah Jochum       Initial creation
//============================================================================
#ifndef ASSIGNMENT6__FRUIT_H_
#define ASSIGNMENT6__FRUIT_H_
#include <string>

using namespace std;

class Fruit {
 private:
  double weight = 0.0;
  double unit_price = 0.0;
  string name = "";
  string DEFAULT_NAME = "A Fruit";

 public:
  double DEFAULT_WEIGHT = 0.0;
  double DEFAULT_UNIT_PRICE = 0.0;

  Fruit();
  Fruit (string fruit_name, double fruit_weight, double fruit_unit_price);
  ~Fruit();

  bool Order(double requested_weight, double& order_cost);

  string GetName();
  double GetWeight();
  double get_unit_price();

  void SetName(string new_fruit_name);
  void SetPrice(double new_price);
  void SetWeight(double new_weight);
  void Display();
};

#endif //ASSIGNMENT6__FRUIT_H_
