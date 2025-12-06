
/*
    Student Name: Maram Sayed
    Student Number: 101304334
    
*/


#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <string>
#include "View.h"
#include "CuRealEstate.h"
#include "Type_Filter.h"
#include "Price_Filter.h"
#include "PriceAndType_Filter.h"

using namespace std;

class Control {
		
	public:
		Control();
		~Control();		
		void launch();
	
	private:
		void initFromFile();
		void resetFilter();
		void filterByPropertyType();
		void filterByPriceRange(); 
		void filterByPriceRangeAndPropertyType();
		void searchListings(); 
		void printCurrentListings();
		void expandListing();
		
		View view;
		List<Listing*> searchResults;
		Filter* filter;
		CuRealEstate market;	

	
};
#endif