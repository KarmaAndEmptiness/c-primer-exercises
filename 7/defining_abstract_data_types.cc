#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
struct Sales_data
{
    // new members: operations on Sales_data objects
    // Functions defined in the class are implicitly inline
    //  After all, the body of isbn doesn’t change the object to which this points, so our function would be more flexible if this were a pointer to const
    std::string isbn() const { return bookNo; }
    // std::string isbn(const Sales_data *const this);

    Sales_data &combine(const Sales_data &);
    double avg_price() const; // 这个const是 this这个指针指向的object的const
    // data members are unchanged
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// pseudo-code illustration of how the implicit this pointer is used
// this code is illegal: we may not explicitly define the this pointer ourselves
// note that this is a pointer to const because isbn is a const member
// std::string Sales_data::isbn(const Sales_data *const this)
// {
//     return this->isbn;
// }
Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold; // add the members of rhs into
    revenue += rhs.revenue;       // the members of ''this'' object
    return *this;                 // return the object on which the function was called
}
// nonmember Sales_data interface functions
Sales_data add(const Sales_data &, const Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);

// exercises
Sales_data add(const Sales_data &s1, const Sales_data &s2)
{
    Sales_data res;
    res.revenue = s1.revenue + s2.revenue;
    return res;
}
std::ostream &print(std::ostream &out, const Sales_data &s)
{
    return out << "bookNo: " << s.bookNo << "  units_sold: " << s.units_sold << "  revenue: " << s.revenue << endl;
}
std::istream &read(std::istream &in, Sales_data &s)
{
    return in >> s.bookNo >> s.units_sold;
}
int main()
{
    return 0;
}