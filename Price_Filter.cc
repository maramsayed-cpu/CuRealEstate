
/*
    Student Name: Maram Sayed
    Student Number: 101304334
    
*/

#include <iostream>
#include <string>
#include <iomanip>

#include "Price_Filter.h"

using namespace std;

Price_Filter::Price_Filter(const Price& min, const Price& max){
    this -> min = min;
    this -> max = max;
}

bool Price_Filter::matches(const Listing& listing) const{
    return listing.getPrice().inRange(min, max);
}

void Price_Filter::print(ostream& ost) const{
    ost << "This filter matches a listing in the given price range." << endl << "$" << std::fixed << std::setprecision(2) << min.getValue() << " $" << std::fixed << std::setprecision(2) << max.getValue();
}