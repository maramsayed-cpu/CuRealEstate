

#ifndef PRICE_H
#define PRICE_H

#include <iostream>
#include <string>

using namespace std; 

class Price{

    friend ostream& operator<<(ostream& ost, const Price& price);
    friend istream& operator>>(istream& is, Price& price);

    public:
        Price(double value);
        Price();

        bool inRange(const Price& min, const Price& max) const;
        void print() const;
        double getValue() const;


    private:
        double value;
};
#endif
