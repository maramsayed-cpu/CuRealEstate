
/*
    Student Name: Maram Sayed
    Student Number: 101304334
    
*/

#include <iostream>
#include <string>
#include "Listing.h"

using namespace std;


Listing::Listing(const string& owner, const string& title, PropertyType propertytype, const string& description, const Price& price){
    this -> owner = owner;
    this -> title = title;
    this -> propertytype = propertytype;
    this -> description = description;
    this -> price = price;
}


bool Listing::lessThan(const Listing& listing) const{
    return (listing.title.compare(this->title) < 0);
}
void Listing::print() const{

    cout << "Owner: " << owner << endl;
    cout << "Title: " << title << endl;
    cout << "Property Type: " << propertyTypeToString(propertytype) << endl;
    cout << "Description: " << description << endl;
    price.print();

}

ostream& operator<<(ostream& ost, const Listing& listing){
  ost << "Owner: " << listing.owner << endl << "Title: " << listing.title << endl << "Property Type: " << propertyTypeToString(listing.propertytype) << endl << "Description: " << listing.description << endl;
  (listing.price).print();
  return ost;
}

const Price& Listing::getPrice() const{
    return price;
}

PropertyType Listing::getType() const{
    return propertytype;
}

const string& Listing::getTitle() const{
    return title;
}

