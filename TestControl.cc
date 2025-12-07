// I didn't write this code

#include "TestControl.h"
#include <limits>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Filter.h"
#include "Type_Filter.h"
#include "Price_Filter.h"
#include "PriceAndType_Filter.h"

using namespace std;

void TestControl::launch(){

    vector<string> menu ={
        "Test add and search Listings - no filter, test for proper printing of Listings",
        "Test add and search Listings - filter by propertytype",
        "Test add and search Listings - filter by price range",
        "Test add and search Listings - filter by price range and propertytype",
        "Test all and get mark"
    };

    int choice = -1;

    // For test purposes
    // CuRealEstate* market = new CuRealEstate;
    // vector<string> users;
    // vector<string> titles;
    // vector<string> categories;
    // vector<string> descriptions;
    // vector<string> prices;
    // initMarket(*market, users, titles, categories, descriptions, prices);
    // delete market;
    
    while (choice!= 0){
        view.menu(menu, choice);
        tester.clearInputBuffer();
        switch(choice){
            case 0: break;
            case 1: tester.recordMark(1, testNoFilter(),8); break;
            case 2: tester.recordMark(2, testFilterByPropertyType(),8); break;
            case 3: tester.recordMark(3, testFilterByPriceRange(),8); break;
            case 4: tester.recordMark(4, testFilterByPriceRangeAndPropertyType(),8); break;
            case 5: tester.recordMark(5, testAllAndMark(), 32); break;
        }
    }
    std::cout<<"exiting program!!!"<<endl;
}

/* *Sigh* Windows embeds a carriage return that is not picked up by getline.
*  This function removes the carriage return from a string.
*/
void stripCR(string& str){
    str.erase(remove(str.begin(), str.end(), '\r'), str.end());
    if (str[0] == '$'){
        str.erase(0,1);
    }
}

void TestControl::initMarket(CuRealEstate& market, 
                        vector<string>& users, 
                        vector<string>& titles, 
                        vector<string>& categories, 
                        vector<string>& descriptions, 
                        vector<string>& prices){
    ifstream listingFile;
    listingFile.open("listings/listings.txt");
    string user, title, description, propertytype, price;


    while( true ){
        std::cout<<"Reading..."<<endl;
        if(!getline(listingFile, user))break;
        getline(listingFile, title);
        getline(listingFile, propertytype);
        getline(listingFile, description);
        getline(listingFile, price);

        // Remove carriage return - Windows, ugh
        stripCR(user);
        stripCR(title);
        stripCR(propertytype);
        stripCR(description);
        stripCR(price);


        users.push_back(user);
        titles.push_back(title);
        categories.push_back(propertytype);
        descriptions.push_back(description);
        prices.push_back(price);

        Price p;

        stringstream ss(price);
        ss >> p;
        market.addListing(user, title,   property::stringToPropertyType(propertytype), description, p);
    }

    listingFile.close();
}

void TestControl::initMarketTitlesOnly(CuRealEstate& market, 
                        vector<string>& titles){
    ifstream listingFile;
    listingFile.open("listings/listings.txt");
    string user, title, description, propertytype, price;


    while( true ){
        std::cout<<"Reading..."<<endl;
        if(!getline(listingFile, user))break;
        getline(listingFile, title);
        getline(listingFile, propertytype);
        getline(listingFile, description);
        getline(listingFile, price);

        titles.push_back(title);

        market.addListing(user, title,   property::stringToPropertyType(propertytype), description, Price(stod(price)));
    }

    listingFile.close();
}

int TestControl::testNoFilter(){
    cout<<"Testing add and search Listings - no filter"<<endl;
    CuRealEstate market;
    vector<string> users;
    vector<string> titles;
    vector<string> categories;
    vector<string> descriptions;
    vector<string> prices;
    initMarket(market, users, titles, categories, descriptions, prices);
    Filter filter;
    List<Listing*> results;
    market.searchListings(filter, results);
    cout<<"Printing all listings"<<endl;
    tester.initCapture();
    view.printListings(results);
    tester.endCapture();


    
    int errors = 0;
    int mark = 0;
    tester.find(titles, errors);
    if (errors>0){
        cout<<"Error: "<<errors<<" titles not found"<<endl;
    }else{
        cout<<"All titles found, 2 marks"<<endl;
        mark += 2;
    }

    tester.find(categories, errors);
    if (errors>0){
        cout<<"Error: "<<errors<<" categories not found!!!!"<<endl;
    }else{
        cout<<"All categories found, 2 marks"<<endl;
        mark += 2;
    }

    tester.find(descriptions, errors);
    if (errors>0){
        cout<<"Error: "<<errors<<" descriptions not found"<<endl;
    }else{
        cout<<"All descriptions found, 2 marks"<<endl;
        mark += 2;
    }

    tester.find(prices, errors);
    if (errors>0){
        cout<<"Error: "<<errors<<" prices not found"<<endl;
    }else{
        cout<<"All prices found, 2 marks"<<endl;
        mark += 2;
    }

    cout<<"Test complete, mark: "<<mark<<"/8"<<endl;
    return mark;

}

int TestControl::testFilterByPropertyType(){
    cout<<"Testing add and search Listings - filter by propertytype"<<endl;
    CuRealEstate market;
    vector<string> users;
    vector<string> titles;
    vector<string> categories;
    vector<string> descriptions;
    vector<string> prices;
    initMarket(market, users, titles, categories, descriptions, prices);
    Type_Filter filter(  property::Villa);
    List<Listing*> results;
    market.searchListings(filter, results);
    cout<<"Printing all listings in propertytype Villa"<<endl;
    tester.initCapture();
    view.printListings(results);
    tester.endCapture();

    int errors = 0;
    int mark = 0;
    vector<int> apartIndices;
    vector<int> absentIndices;
    for (int i = 0; i < categories.size(); ++i){
        if (categories[i] == "Villa"){
            apartIndices.push_back(i);
        }else{
            absentIndices.push_back(i);
        }
    }
    tester.find(apartIndices, titles, errors);
    if (errors>0){
        cout<<"Error: "<<errors<<" titles not found"<<endl;
    }else{
        cout<<"All titles found, 2 marks"<<endl;
        mark += 2;
    }

    tester.confirmAbsent(absentIndices, titles, errors);
    if (errors>0){
        cout<<"Error: "<<errors<<" titles found for absent categories"<<endl;
    }else{
        cout<<"No titles found for absent categories, 2 marks"<<endl;
        mark += 2;
    }

    results.clear();

    filter =   Type_Filter(  property::Bungalow);
    market.searchListings(filter, results);
    cout<<"Printing all listings in propertytype Bungalow"<<endl;
    tester.initCapture();
    view.printListings(results);
    tester.endCapture();

    errors = 0;
    vector<int> miscIndices;
    absentIndices.clear();
    for (int i = 0; i < categories.size(); ++i){
        if (categories[i] == "Bungalow"){
            miscIndices.push_back(i);
        }else{
            absentIndices.push_back(i);
        }
    }

    tester.find(miscIndices, titles, errors);
    if (errors>0){
        cout<<"Error: "<<errors<<" titles not found"<<endl;
    }else{
        cout<<"All titles found, 2 marks"<<endl;
        mark += 2;
    }

    tester.confirmAbsent(absentIndices, titles, errors);
    if (errors>0){
        cout<<"Error: "<<errors<<" titles found for absent categories"<<endl;
    }else{
        cout<<"No titles found for absent categories, 2 marks"<<endl;
        mark += 2;
    }


    cout<<"Test complete, mark: "<<mark<<"/8"<<endl;
    return mark;

}


int TestControl::testFilterByPriceRange(){
    cout<<"Testing add and search Listings - filter by price range"<<endl;
    CuRealEstate market;
    vector<string> users;
    vector<string> titles;
    vector<string> categories;
    vector<string> descriptions;
    vector<string> prices;
    initMarket(market, users, titles, categories, descriptions, prices);

    Price_Filter filter(Price(20000), Price(950000));
    List<Listing*> results;
    market.searchListings(filter, results);
    cout<<"Printing all listings in price range 20 000 - 950 000"<<endl;
    tester.initCapture();
    view.printListings(results);
    tester.endCapture();

    cout<<"Done printing..."<<endl;

    int errors = 0;
    int mark = 0;
    vector<int> cheapIndices;
    vector<int> absentIndices;
    for (int i = 0; i < prices.size(); ++i){
        if (stod(prices[i]) >= 20000 && stod(prices[i]) <= 950000){
            cheapIndices.push_back(i);
        }else{
            absentIndices.push_back(i);
        }
    }
    tester.find(cheapIndices, titles, errors);
    if (errors>0){
        cout<<"Error: "<<errors<<" titles not found"<<endl;
    }else{
        cout<<"All titles found, 2 marks"<<endl;
        mark += 2;
    }

    tester.confirmAbsent(absentIndices, titles, errors);
    if (errors>0){
        cout<<"Error: "<<errors<<" titles found for absent prices"<<endl;
    }else{
        cout<<"No titles found for absent prices, 2 marks"<<endl;
        mark += 2;
    }

    results.clear();
    filter = Price_Filter(Price(2000000), Price(1000000000));
    market.searchListings(filter, results);
    cout<<"Printing all listings in price range 2 000 000 - 1 000 000 000"<<endl;
    tester.initCapture();
    view.printListings(results);
    tester.endCapture();

    errors = 0;
    vector<int> midIndices;
    absentIndices.clear();
    for (int i = 0; i < prices.size(); ++i){
        if (stod(prices[i]) >=2000000){
            midIndices.push_back(i);
        }else{
            absentIndices.push_back(i);
        }
    }

    tester.find(midIndices, titles, errors);
    if (errors>0){
        cout<<"Error: "<<errors<<" titles not found"<<endl;
    }else{
        cout<<"All titles found, 2 marks"<<endl;
        mark += 2;
    }

    tester.confirmAbsent(absentIndices, titles, errors);
    if (errors>0){
        cout<<"Error: "<<errors<<" titles found for absent prices"<<endl;
    }else{
        cout<<"No titles found for absent prices, 2 marks"<<endl;
        mark += 2;
    }

    cout<<"Test complete, mark: "<<mark<<"/8"<<endl;
    return mark;
}

int TestControl::testFilterByPriceRangeAndPropertyType(){
    cout<<"Testing add and search Listings - filter by price range and propertytype"<<endl;
    CuRealEstate market;
    vector<string> users;
    vector<string> titles;
    vector<string> categories;
    vector<string> descriptions;
    vector<string> prices;
    initMarket(market, users, titles, categories, descriptions, prices);
    PriceAndType_Filter filter(Price(0), Price(200000),   property::Apartment);
    List<Listing*> results;
    market.searchListings(filter, results);
    cout<<"Printing all listings in price range 0-200 000 and propertytype Aparment"<<endl;
    tester.initCapture();
    view.printListings(results);
    tester.endCapture();

    int errors = 0;
    int mark = 0;
    vector<int> cheapapartIndices;
    vector<int> absentIndices;
    for (int i = 0; i < prices.size(); ++i){
        if (stod(prices[i]) <= 200000 && categories[i] == "Apartment"){
            cheapapartIndices.push_back(i);
        }else{
            absentIndices.push_back(i);
        }
    }
    tester.find(cheapapartIndices, titles, errors);
    if (errors>0){
        cout<<"Error: "<<errors<<" titles not found"<<endl;
    }else{
        cout<<"All titles found, 2 marks"<<endl;
        mark += 2;
    }

    tester.confirmAbsent(absentIndices, titles, errors);
    if (errors>0){
        cout<<"Error: "<<errors<<" titles found for absent prices and categories"<<endl;
    }else{
        cout<<"No titles found for absent prices and categories, 2 marks"<<endl;
        mark += 2;
    }

    results.clear();
    filter = PriceAndType_Filter(Price(200000), Price(10000000),   property::Mansion);
    market.searchListings(filter, results);
    cout<<"Printing all listings in price range 200 000-10 000 000 and propertytype Mansion"<<endl;
    tester.initCapture();
    view.printListings(results);
    tester.endCapture();

    errors = 0;
    vector<int> midMiscIndices;
    absentIndices.clear();
    for (int i = 0; i < prices.size(); ++i){
        if (stod(prices[i]) >=200000 && stod(prices[i]) <= 10000000 && categories[i] == "Mansion"){
            midMiscIndices.push_back(i);
        }else{
            absentIndices.push_back(i);
        }
    }

    tester.find(midMiscIndices, titles, errors);
    if (errors>0){
        cout<<"Error: "<<errors<<" titles not found"<<endl;
    }else{
        cout<<"All titles found, 2 marks"<<endl;
        mark += 2;
    }

    tester.confirmAbsent(absentIndices, titles, errors);
    if (errors>0){
        cout<<"Error: "<<errors<<" titles found for absent prices and categories"<<endl;
    }else{
        cout<<"No titles found for absent prices and categories, 2 marks"<<endl;
        mark += 2;
    }

    cout<<"Test complete, mark: "<<mark<<"/8"<<endl;
    return mark;
}


int TestControl::testAllAndMark(){
    int mark = 0;
    mark += testNoFilter();
    mark += testFilterByPropertyType();
    mark += testFilterByPriceRange();
    mark += testFilterByPriceRangeAndPropertyType();
    return mark;

}
