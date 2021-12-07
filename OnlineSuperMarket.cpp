//============================================================================
// File Name   : OnlineSuperMarket.cpp
// Author      : Sarah Jochum
// Copyright   : 2021 copyright
// Description :  A class that outlines an online supermarket.

// Disclaimer: Google Coding style. 4 space instead of tab and 2 space indent.
// Revision History:
// Date              Version     Change ID         Author             Comment
// 12-06-21          1.0           001             Sarah Jochum       Initial creation
//============================================================================

#include "OnlineSuperMarket.h"
#include <string>
#include "Fruit.h"
#include <iostream>
#include <iomanip>

using namespace std;

OnlineSuperMarket::OnlineSuperMarket() {
}

OnlineSuperMarket::OnlineSuperMarket(string market_name, string market_web_address) {
  name = market_name;
  web_address = market_web_address;
}

OnlineSuperMarket::~OnlineSuperMarket()
{
  cout << "Online Supermarket " << name << " at " << web_address << " is already closed.\n";
}

string OnlineSuperMarket::get_market_name() {
  return name;
}

string OnlineSuperMarket::get_web_address() {
  return web_address;
}

void OnlineSuperMarket::Init() {
  string fruit_names[] = {"Banana", "Strawberry", "Orange", "Grapes", "Watermelon", "Apple", "Blueberry", "Mango"};
  double low_price[] = {0.50, 2.10, 2.00, 2.15, 0.60, 1.50, 3.00, 2.25};
  double high_price[] = {0.85, 3.50, 3.50, 4.50, 1.45, 3.20, 4.50, 3.25};
  double min_weight = 10.0;
  double max_weight = 50.0;
  double price = 0.0;
  double weight = 0.0;

  srand(static_cast <unsigned int> (time(0)));

  for (int i = 0; i < SIZE; i++) {
    fruit_list[i].SetName(fruit_names[i]);

    price = low_price[i]
        + static_cast<double> ( rand()) / (static_cast<double> ( RAND_MAX / (high_price[i] - low_price[i])));
    fruit_list[i].SetPrice(price);

    weight = min_weight + static_cast<double> ( rand()) / (static_cast<double> ( RAND_MAX / (max_weight - min_weight)));
    fruit_list[i].SetWeight(weight);
  }
}

void OnlineSuperMarket::Sort() {
  bool swapped = true;
  int j = 0;
  Fruit temp_fruit;
  while (swapped) {
    swapped = false;
    j++;

    for (int i = 0; i < SIZE - j; i++) {
      if (fruit_list[i].GetName().compare(fruit_list[i + 1].GetName()) > 0) {
        temp_fruit = fruit_list[i];
        fruit_list[i] = fruit_list[i + 1];
        fruit_list[i + 1] = temp_fruit;
        swapped = true;
      }
    }
  }
}

void OnlineSuperMarket::Run() {
  cout << " \n----------------------------------------------" << endl;
  cout << "\tWelcome to Hankook Supermarket!" << endl;
  cout << "----------------------------------------------" << endl;

  bool keep_alive = true;
  char option = '\0'; //null character
  string selected_fruit = " ";
  double selected_weight = 0.0;
  int fruit_index = 0;
  double order_cost = 0.0;
  bool success = false;
  double final_cost = 0.0;

  do {
    Menu();
    option = GetOption();

    switch (option) {
      case 'o':
      case 'O':
        selected_fruit = GetUserFruitSelection();
        selected_weight = GetUserWeight();
        fruit_index = Find(selected_fruit);

        if (fruit_index == -1) {
          cout << selected_fruit << "is not available at this time." << endl;
          break;
        }

        success = fruit_list[fruit_index].Order(selected_weight, order_cost);

        if (!success) {
          cout << "Sorry, we were not able to complete your order as specified." << endl;
          cout << "The amount of " << selected_fruit << " available is " ;
          cout << fruit_list[fruit_index].GetWeight() << "lbs" << endl;
          break;
        }
        final_cost = order_cost * (1 + SALES_TAX_RATE);
        cout << "You have placed an order! Thank you. ";
        cout << "Your total is: $" << setprecision(2) << final_cost;
        break;
      case 'q':
      case 'Q':
        keep_alive = Quit();
        break;
      default:
        cout << "Input unrecognized. Please enter O or Q.";
        break;
    }
  } while (keep_alive);

}

void OnlineSuperMarket::ShowFruits() {
  //ShowFruits: display all fruits using Fruit objects' Display function.
  cout << "---------- Showing Fruits --------------" << endl;
  for(int i = 0; i < SIZE; i++){
    fruit_list[i].Display();
  }
}

int OnlineSuperMarket::Find(string fruit_name) {
  Sort();
  int first_index = 0;
  int last_index = SIZE - 1;
  int middle_index = 0;

  while (first_index <= last_index) {
    middle_index = (first_index + last_index) / 2;
    if (fruit_list[middle_index].GetName() == fruit_name) {
      return middle_index;
    } else if (fruit_list[middle_index].GetName() > fruit_name) {
      last_index = middle_index - 1;
    } else {
      first_index = middle_index + 1;
      }
    }
    return -1;
  }

bool OnlineSuperMarket::Quit() {
    cout << "Thanks for your visit and come again!" << endl;
    return false;
  }

char OnlineSuperMarket::GetOption() {
    char option = '\0';
    cin.clear();
    fflush(stdin);
    cout << "\nSelect an option: ";
    cin >> option;
    return option;
  }

void OnlineSuperMarket::Menu() {
  cout << "Please chose an option: \n Enter O to place an order. \n Enter Q to Quit." << endl;
  }

string OnlineSuperMarket::GetUserFruitSelection() {
  string chosen_fruit = " ";
  cin.clear();
  fflush(stdin);
  cout << "What fruit would you like to order? ";
  cin >> chosen_fruit;
  return chosen_fruit;
  }

double OnlineSuperMarket::GetUserWeight() {
  double chosen_weight = 0.0;
  cin.clear();
  fflush(stdin);
  cout << "Please enter a weight: ";
  cin >> chosen_weight;
  return chosen_weight;
  }


