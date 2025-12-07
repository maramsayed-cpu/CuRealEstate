

#include <iostream>
#include <string>
#include <iomanip>

#include "PriceAndType_Filter.h"

using namespace std;

PriceAndType_Filter::PriceAndType_Filter(const Price& min, const Price& max, PropertyType propertytype): Price_Filter(min, max), Type_Filter(propertytype){};

bool PriceAndType_Filter::matches(const Listing& listing) const{
    return (Price_Filter::matches(listing) && Type_Filter::matches(listing));
    
}

void PriceAndType_Filter::print(ostream& ost) const{
    ost << "This filter matches a listing with the given property type and price range." << endl << "Property Type: " << propertyTypeToString(propertytype) << endl << "$" << std::fixed << std::setprecision(2) << min.getValue() << " $" << std::fixed << std::setprecision(2) << max.getValue();
}
