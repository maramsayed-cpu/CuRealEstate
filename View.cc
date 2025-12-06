
/*
    Student Name: Maram Sayed
    Student Number: 101304334
    
*/

#include "View.h"
#include "Filter.h"
#include <limits>
#include <vector>



void View::menu(vector<string>& menu, int& choice, const Filter& filter)
{
  cout << endl;
  cout << "Current filter: " << filter << endl;
  cout << "Please make a selection:"<< endl<<endl;
  for (int i = 0; i < menu.size(); ++i){
    cout<<"  ("<<i+1<<") "<<menu[i]<<endl;
  }
  cout << "  (0) Exit" << endl<<endl;

  cout << "Enter your selection: ";
  cin >> choice;
  if (choice == 0)
    return;

  while (choice < 0 || choice > menu.size()) {
    cout << "Enter your selection: ";
    cin >> choice;
  }
}

void View::menu(vector<string>& menu, int& choice)
{
  cout << endl;
  cout << "Please make a selection:"<< endl<<endl;
  for (int i = 0; i < menu.size(); ++i){
    cout<<"  ("<<i+1<<") "<<menu[i]<<endl;
  }
  cout << "  (0) Exit" << endl<<endl;

  cout << "Enter your selection: ";
  cin >> choice;
  if (choice == 0)
    return;

  while (choice < 0 || choice > menu.size()) {
    cout << "Enter your selection: ";
    cin >> choice;
  }
}

void View::printListings(const List<Listing*>& listings)
{
  for (int i = 0; i < listings.getSize(); ++i){
    cout  << i+1 << ")\n" << *listings[i] << endl;
  }
}

void View::listingMenu(const List<Listing*>& listings, int& choice)
{
  cout << endl;
  cout << "Please make a selection:"<< endl<<endl;
  for (int i = 0; i < listings.getSize(); ++i){
    cout << i+1 << ")\n" << *listings[i] << endl;
  }
  cout << "  (0) Exit" << endl<<endl;

  cout << "Enter your selection: ";
  cin >> choice;
  if (choice == 0)
    return;

  while (choice < 0 || choice > listings.getSize()) {
    cout << "Enter your selection: ";
    cin >> choice;
  }
}

void View::printListing(const Listing& listing)
{
  cout << listing <<endl;
}

void View::promptPriceRange(Price& min, Price& max)
{
  cout << "Enter the minimum price: ";
  cin >> min;
  cout << "Enter the maximum price: ";
  cin >> max;
}

void View::promptPropertyType(property::PropertyType& propertytype)
{
  int choice;
  cout << "Please select a propertytype:"<< endl<<endl;
  for (int i = 0; i <  property::PropertyType::size; ++i){
    cout << "  (" << i+1 << ") " <<   property::  propertyTypeToString(static_cast<property::PropertyType>(i)) << endl;
  }
  cout << "Enter your selection: ";
  cin >> choice;
  while (choice < 1 || choice >  property::PropertyType::size) {
    cout << "Enter your selection: ";
    cin >> choice;
  }
  propertytype = static_cast<property::PropertyType>(choice-1);
}