
/*
    Student Name: Maram Sayed
    Student Number: 101304334
    
*/

#ifndef TESTCONTROL_H
#define TESTCONTROL_H

#include <iostream>
#include <string>
#include <random>
#include <unordered_set>
#include <sstream>
#include "Listing.h"
#include "View.h"
#include "Tester.h"
#include "CuRealEstate.h"

using namespace std;

class TestControl {
		
	public:
		void launch();
	
	private:
		void initMarket(CuRealEstate& market, 
						vector<string>& user, 
						vector<string>& title, 
						vector<string>& propertytype, 
						vector<string>& description, 
						vector<string>& price);
		void initMarketTitlesOnly(CuRealEstate& market, 
                        vector<string>& titles);
		
		//  vector<string> menu ={
		// 	"Test add and search Listings - no filter",
		// 	"Test add and search Listings - filter by propertytype",
		// 	"Test add and search Listings - filter by price range",
		// 	"Test add and search Listings - filter by price range and propertytype",
		// 	"Test all and get mark"
    	// };
		int testNoFilter();
		int testFilterByPropertyType();
		int testFilterByPriceRange();
		int testFilterByPriceRangeAndPropertyType();
		int testAllAndMark();

		

		View view;
		Tester tester;

		
	
};
#endif