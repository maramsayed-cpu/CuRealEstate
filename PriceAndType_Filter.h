
/*
    Student Name: Maram Sayed
    Student Number: 101304334
    
*/

#ifndef PRICEANDTYPE_FILTER_H
#define PRICEANDTYPE_FILTER_H

#include <iostream>
#include <string>

#include "Price_Filter.h"
#include "Type_Filter.h"

using property::PropertyType;


class PriceAndType_Filter: public Price_Filter, public Type_Filter{
    
    public:
        PriceAndType_Filter(const Price& min, const Price& max, PropertyType propertytype);
        virtual bool matches(const Listing& listing) const;
        virtual void print(ostream& ost) const;
};

#endif
