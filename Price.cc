

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

#include "Price.h"

using namespace std;

Price::Price(double value){
    this -> value = value;
}

Price::Price(){
    this -> value = 0;
}

bool Price::inRange(const Price& min, const Price& max) const{
    return ((this -> value >= min.value) && (this -> value <= max.value));
    
}

void Price::print() const{
    cout << "$" << std::fixed << std::setprecision(2) << value << endl;
}

ostream& operator<<(ostream& ost, const Price& price){
  ost<< std::fixed << std::setprecision(2) << price.value;
    return ost;
}

istream& operator>>(istream& is, Price& price){
    string input;
    string inputValue;
    
    is >> input;

    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '.'){
            break;
        }
        else if (std::isdigit(input[i])) {
            inputValue += input[i];
        }
    }

    price.value = std::stod(inputValue);

    return is;
}

double Price::getValue() const{
    return value;
}
