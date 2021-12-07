//============================================================================
// File Name   : OnlineSuperMarket.h
// Author      : Sarah Jochum
// Copyright   : 2021 copyright
// Description :  A class that outlines an online supermarket.

// Disclaimer: Google Coding style. 4 space instead of tab and 2 space indent.
// Revision History:
// Date              Version     Change ID         Author             Comment
// 12-06-21          1.0           001             Sarah Jochum       Initial creation
//============================================================================

#ifndef ASSIGNMENT6__ONLINESUPERMARKET_H_
#define ASSIGNMENT6__ONLINESUPERMARKET_H_
#include <string>
#include "Fruit.h"

using namespace std;

class OnlineSuperMarket {
 public:
  const static int SIZE = 8;
  constexpr static double SALES_TAX_RATE = 0.095;

  OnlineSuperMarket();
  OnlineSuperMarket(string market_name, string market_web_address);
  ~OnlineSuperMarket();

  string get_market_name();
  string get_web_address();

  void Init();
  void Sort();
  void Run();
  void ShowFruits();

  char GetOption();

 private:
  Fruit fruit_list[SIZE];
  string name = "";
  string web_address = "";

  int Find(string fruit_name);

  bool Quit();

  void Menu();
  string GetUserFruitSelection();
  double GetUserWeight();
};

#endif //ASSIGNMENT6__ONLINESUPERMARKET_H_


