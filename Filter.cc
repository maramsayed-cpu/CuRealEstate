

#include <iostream>
#include <string>

#include "Filter.h"

using namespace std;


Filter::~Filter(){};
bool Filter::matches(const Listing& listing) const{
    return true;
}

void Filter::print(ostream& ost) const{
    ost << "This filter will select everything." << endl;
}

ostream& operator<<(ostream& ost, const Filter& filter) {
    filter.print(ost);
    return ost;
}
