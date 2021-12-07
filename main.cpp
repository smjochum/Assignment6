//============================================================================
// File Name   : main.cpp
// Author      : Sarah Jochum
// Copyright   : 2021 copyright
// Description :  An application that allows users to order from an online supermarket.

// Disclaimer: Google Coding style. 4 space instead of tab and 2 space indent.
// Revision History:
// Date              Version     Change ID         Author             Comment
// 12-06-21          1.0           001             Sarah Jochum       Initial creation
//============================================================================
#include "OnlineSuperMarket.h"
#include <iostream>
#include <string>

int main() {
  OnlineSuperMarket *market_ptr = nullptr;
  OnlineSuperMarket market("Hankook", "http://www.hankooksupermarket.com/");
  market_ptr = &market;
  market_ptr->ShowFruits();

  market_ptr->Init();
  market_ptr->ShowFruits();

  market_ptr->Sort();
  market_ptr->ShowFruits();
  market_ptr->Run();

}
