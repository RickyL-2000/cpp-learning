#include "Sales_data.h"
#include <iostream>
#include <string>

istream &read(istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

double Sales_data::avg_price() const {  /* also need to insure the *const* attribute */
    if (units_sold)
        return revenue/units_sold;
    else
        return 0;
}

Sales_data& Sales_data::combine(const Sales_data &rhs) {
    this->units_sold += rhs.units_sold;     // 什么时候要写this-> ???
    this->revenue += rhs.revenue;
    return *this;   // 返回调用该函数的对象
}


// constructor, defined outside the class
Sales_data::Sales_data(istream &is) {
    read(is, *this);
}