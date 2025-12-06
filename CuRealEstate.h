
/*
    Student Name: Maram Sayed
    Student Number: 101304334
    
*/

#ifndef CUREALESTATE_H
#define CUREALESTATE_H

#include <iostream>
#include <string>

#include "Listing.h"
#include "List.h"
#include "Price.h"
#include "Filter.h"

using namespace std;

using property::PropertyType;


class CuRealEstate{

    public:
        ~CuRealEstate();
        bool addListing(const string& owner, const string& title, PropertyType propertytype, const string& description, const Price& price);
        void removeListing(const string& title);
        void searchListings(Filter& filter, List<Listing*>& searchList) const;

    private:

        List<Listing*> listings;

};
#endif