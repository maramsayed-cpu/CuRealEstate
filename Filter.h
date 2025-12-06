
/*
    Student Name: Maram Sayed
    Student Number: 101304334
    
*/

#ifndef FILTER_H
#define FILTER_H

#include <iostream>
#include <string>

#include "Listing.h"

using namespace std;

class Filter{

    friend ostream& operator<<(ostream& ost, const Filter& filter);

    public:

        virtual ~Filter();

        virtual bool matches(const Listing& listing) const;
        virtual void print(ostream& ost) const;

};
#endif