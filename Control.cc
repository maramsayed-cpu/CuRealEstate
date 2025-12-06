
/*
    Student Name: Maram Sayed
    Student Number: 101304334
    
*/

#include "Control.h"
#include "View.h"
#include <fstream>
#include <limits>
#include <vector>

using namespace std;

Control::Control(){
    filter = new Filter;
}

Control::~Control(){
    delete filter;
}

void Control::launch(){
    cout<<"Launching..."<<endl;
    initFromFile();
    searchListings();
    cout<<"Done initializing"<<endl;
    int choice = -1;


    while (true){
        choice = -1;
        vector<string> menu ={
            "No filter",
            "Filter by property type",
            "Filter by price range",
            "Filter by price range and property type",
            "Print current listings",
            "Expand listing"
        };

        view.menu(menu, choice, *filter);
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
        if (choice == 0)break;
        switch (choice)
        {
        case 1:
            resetFilter(); break;
        case 2:
            filterByPropertyType(); break;
        case 3:
            filterByPriceRange(); break;
        case 4:
            filterByPriceRangeAndPropertyType(); break;
        case 5:
            printCurrentListings(); break;
        case 6:
            expandListing(); break;
        default:
            break;
        }
        
    }

    cout << "Good-bye!"<<endl;
}



void Control::initFromFile(){
    ifstream listingFile;
    listingFile.open("listings/listings.txt");
    string user, title, description, propertytype, price;


    while( true ){
        cout<<"Reading..."<<endl;
        if(!getline(listingFile, user))break;
        getline(listingFile, title);
        getline(listingFile, propertytype);
        getline(listingFile, description);
        getline(listingFile, price);
        market.addListing(user, title,   property::stringToPropertyType(propertytype), description, Price(stod(price)));
    }

    listingFile.close();
    
}

void Control::resetFilter(){
    delete filter;
    filter = new Filter;
    searchListings();
}

void Control::filterByPropertyType(){
    property::PropertyType propertytype;
    view.promptPropertyType(propertytype);
    delete filter;
    filter = new   Type_Filter(propertytype);
    searchListings();
}

void Control::filterByPriceRange(){
    Price min, max;
    view.promptPriceRange(min, max);
    delete filter;
    filter = new Price_Filter(min, max);
    searchListings();
}

void Control::filterByPriceRangeAndPropertyType(){
    property::PropertyType propertytype;
    view.promptPropertyType(propertytype);
    Price min, max;
    view.promptPriceRange(min, max);
    delete filter;
    filter = new PriceAndType_Filter(min, max, propertytype);
    searchListings();
}

void Control::searchListings(){
    searchResults.clear();
    market.searchListings(*filter, searchResults);
}

void Control::printCurrentListings(){
    view.printListings(searchResults);
}

void Control::expandListing(){
    int choice = -1;
    view.listingMenu(searchResults, choice);
    if (choice != 0){
        view.printListing(*searchResults[choice-1]);
    }
}
