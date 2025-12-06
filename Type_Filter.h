
/*
    Student Name: Maram Sayed
    Student Number: 101304334
    
*/

#ifndef TYPE_FILTER_H
#define TYPE_FILTER_H

#include <iostream>
#include <string>

#include "PropertyType.h"
#include "Filter.h"

using namespace std;
using property::PropertyType;

class Type_Filter: public virtual Filter{

    public:

        Type_Filter(PropertyType propertytype);
        virtual bool matches(const Listing& listing) const;
        virtual void print(ostream& ost) const;


    protected:
        PropertyType propertytype;

        
};
#endif