

#ifndef PRICE_FILTER_H
#define PRICE_FILTER_H

#include <iostream>
#include <string>

#include "Price.h"
#include "Filter.h"

using namespace std;

class Price_Filter: public virtual Filter{

    public:

        Price_Filter(const Price& min, const Price& max);
        virtual bool matches(const Listing& listing) const;
        virtual void print(ostream& ost) const;


    protected:
        Price min;
        Price max;

        
};
#endif
