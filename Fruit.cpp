//============================================================================
// File Name   : Fruit.cpp
// Author      : Sarah Jochum
// Copyright   : 2021 copyright
// Description :  A class that represents a fruit within a supermarket.

// Disclaimer: Google Coding style. 4 space instead of tab and 2 space indent.
// Revision History:
// Date              Version     Change ID         Author             Comment
// 12-06-21          1.0           001             Sarah Jochum       Initial creation
//============================================================================

#include "Fruit.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

Fruit::Fruit() {
  name = DEFAULT_NAME;
  weight = DEFAULT_WEIGHT;
  unit_price = DEFAULT_UNIT_PRICE;
}

Fruit::Fruit(string fruit_name, double fruit_weight, double fruit_unit_price) {
  name = fruit_name;
  weight = fruit_weight;
  unit_price = fruit_unit_price;
}

Fruit::~Fruit() {
  cout << fixed << setprecision(2);
  cout << "Fruit: " << name << ", " << "Weight = " << weight << " rotten." << endl;
}

void Fruit::Display() {
  int width = 25;
  cout << fixed << setprecision(2);
  cout << left << setw(width)<< name << setw(width) << right << weight << setw(width)<< right << unit_price << endl;
}

bool Fruit::Order(double requested_weight, double &order_cost) {
  cout << "Requested weight: " << requested_weight;
  if (requested_weight > weight) {
    order_cost = 0;
    cout << "weight: " << weight;
    cout << "Order returned false";
    return false;
  } else {
    cout << "Order returned true";
    this->weight -= requested_weight;
    order_cost = requested_weight * unit_price;
    return true;
  }
}
string Fruit::GetName() {
  return name;
}
double Fruit::GetWeight() {
  return weight;
}
void Fruit::SetName(string new_fruit_name) {
  this->name = new_fruit_name;
}
void Fruit::SetPrice(double new_price) {
  this->unit_price = new_price;
}
void Fruit::SetWeight(double new_weight) {
  this->weight = new_weight;
}


