
/*
    Student Name: Maram Sayed
    Student Number: 101304334
    
*/

#ifndef LISTING_H
#define LISTING_H

#include <iostream>
#include <string>
#include "Price.h"
#include "PropertyType.h"

using property::PropertyType;


class Listing{

    friend ostream& operator<<(ostream& ost, const Listing& listing);

    public:
        Listing(const string& owner, const string& title, PropertyType propertytype, const string& description, const Price& price);
        

        bool lessThan(const Listing& listing) const;
        void print() const;
        const Price& getPrice() const;
        PropertyType getType() const;
        const string& getTitle() const;


    private:
        Price price;
        PropertyType propertytype;
        string owner;
        string title;
        string description;
};
#endif