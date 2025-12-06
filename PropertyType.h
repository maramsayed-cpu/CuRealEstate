
/*
    Student Name: Maram Sayed
    Student Number: 101304334
    
*/

#ifndef PROPERTYTYPE_H
#define PROPERTYTYPE_H

#include <iostream>
#include <string>
#include <vector>

namespace property{
    
    enum PropertyType {Bungalow, Duplex, Apartment, Condo, Townhouse, Villa, Mansion, size};
    std::string   propertyTypeToString(PropertyType propertytype);
    PropertyType stringToPropertyType(const std::string& propertytype);
    
};
#endif