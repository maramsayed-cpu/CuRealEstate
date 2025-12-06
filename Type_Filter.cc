
/*
    Student Name: Maram Sayed
    Student Number: 101304334
    
*/

#include <iostream>
#include <string>

#include "Type_Filter.h"

using namespace std;


Type_Filter::Type_Filter(PropertyType propertytype){
    this -> propertytype = propertytype;
}

bool Type_Filter::matches(const Listing& listing) const{

    return (listing.getType() == propertytype);
}
void Type_Filter::print(ostream& ost) const{
    ost << "This filter matches a listing with the given property type." << endl << "Property Type: " << propertyTypeToString(propertytype) << endl;
}



    