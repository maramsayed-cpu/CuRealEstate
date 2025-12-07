// I didn't write this code

#include "PropertyType.h"



std::string   property::propertyTypeToString(PropertyType propertytype){
    switch(propertytype){
        case Bungalow: return "Bungalow";
        case Duplex: return "Duplex";
        case Apartment: return "Apartment";
        case Condo: return "Condo";
        case Townhouse: return "Townhouse";
        case Villa: return "Villa";
        case Mansion: return "Mansion";
        default: break;
    }
    return "misc";
}

  property::PropertyType   property::stringToPropertyType(const std::string& propertytype){
    if (propertytype.find("Duplex")!=std::string::npos) return   Duplex;
    if (propertytype.find("Apartment")!=std::string::npos) return   Apartment;
    if (propertytype.find("Condo")!=std::string::npos) return   Condo;
    if (propertytype.find("Townhouse")!=std::string::npos) return   Townhouse;
    if (propertytype.find("Villa")!=std::string::npos) return   Villa;
    if (propertytype.find("Mansion")!=std::string::npos) return   Mansion;

    return   Bungalow; //default
}

