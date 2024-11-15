#include <iostream>
#include <string>
// Using the class or struct Keyword
// if we use the struct keyword, the members defined before the first access specifier are public; if we use class, then the members are private.
class Sales_data
{
    // Friend declarations may appear only inside a class definition; they may appear anywhere in the class. Friends are not members of the class and are not affected by the access control of the section in which they are declared.
    // friend declarations for nonmember Sales_data operations added
    // Ordinarily it is a good idea to group friend declarations together at the beginning or end of the class definition.
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend std::istream &read(std::istream &, Sales_data &);
    friend std::ostream &print(std::ostream &, const Sales_data &);

    // Some compilers allow calls to a friend function when there is no ordinary declaration for that function.
    // g++ 环境将friend funtions 定义在class 内部，可以运行
    // friend Sales_data add(const Sales_data &s1, const Sales_data &s2)
    // {
    //     Sales_data res;
    //     res.units_sold = s1.units_sold + s2.units_sold;
    //     return res;
    // }
    // friend std::ostream &print(std::ostream &os, const Sales_data &s)
    // {
    //     return os << s.units_sold;
    // }

    // other members and access specifiers as before
public:
    Sales_data() = default;
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {}
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(unsigned n) : units_sold(n) {}
    Sales_data(std::istream &);
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// declarations for nonmember parts of the Sales_data interface
// If we want users of the class to be able to call a friend function, then we must also declare the function separately from the friend declaration.
Sales_data add(const Sales_data &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);

Sales_data add(const Sales_data &s1, const Sales_data &s2)
{
    Sales_data res;
    res.units_sold = s1.units_sold + s2.units_sold;
    return res;
}

std::ostream &print(std::ostream &os, const Sales_data &s)
{
    return os << s.units_sold;
}
int main()
{
    Sales_data s1(1);
    Sales_data s2(2);
    Sales_data sum;
    sum = add(s1, s2);
    print(std::cout, sum);
    std::cout << std::endl;
    return 0;
}