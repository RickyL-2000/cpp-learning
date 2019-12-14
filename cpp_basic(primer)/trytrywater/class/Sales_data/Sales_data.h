#include <string>
#include <iostream>

struct Sales_data {
    // constructors
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo (s) {}    /* 其他member被与默认相同的方式隐式初始化 */
    Sales_data(const std::string &s, unsigned n, double p):
                bookNo(s), units_sold(n), revenue(p*n) { }  /* 构造函数初始值列表 */
    Sales_data(std::istream &);

    // members functions
    std::string isbn() const {return bookNo;}   /* no need to write this->bookNo (????) */
    Sales_data& combine(const Sales_data&);
    double avg_price() const;   /* this const means *const member functino* */

    // members
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

};
// non-members
Sales_data add(const Sales_data &, const Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);
