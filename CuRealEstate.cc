

#include <iostream>
#include <string>

#include "CuRealEstate.h"

CuRealEstate::~CuRealEstate() {
    for (int i = 0; i < listings.getSize(); i++) {
        delete listings[i];  
    }
}

bool CuRealEstate::addListing(const string& owner, const string& title, PropertyType propertytype, const string& description, const Price& price){
    if (!listings.isFull()){
        listings += new Listing(owner, title, propertytype, description, price);
        return true;
    }
    return false;

}

void CuRealEstate::removeListing(const string& title) {
    for (int i = 0; i < listings.getSize(); i++){
        if(listings[i]->getTitle() == title) {
            Listing* goner = listings[i];
            listings -= listings[i];
            delete goner;
            return;
        }
    }
    cout << "No matching listing." << endl;
}


void CuRealEstate::searchListings(Filter& filter, List<Listing*>& searchList) const{
    
    for (int i = 0; i < listings.getSize(); i++){
        if(filter.matches(*listings[i])) {
            searchList += listings[i];
        }
    }
}
