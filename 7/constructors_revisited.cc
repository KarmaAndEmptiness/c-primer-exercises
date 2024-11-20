#include <iostream>
#include <string>
#include <vector>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// Constructor Initializers Are Sometimes Required
// Members that are const or references must be initialized.
// We must use the constructor initializer list to provide values for members that are const, reference, or of a class type that does not have a default constructor.
// 没有默认构造函数的class
class ConstRef
{
public:
    ConstRef(int ii);

private:
    int i;
    const int ci;
    int &ri;
};

// error: ci and ri must be initialized
// ConstRef::ConstRef(int ii)
// {            // assignments:
// i = ii;  // ok
// By the time the body of the constructor begins executing, initialization is complete.
//     ci = ii; // error: cannot assign to a const
//     ri = i;  // error: ri was never initialized
// }

//  Our only chance to initialize const or reference data members is in the constructor initializer.
// ok: explicitly initialize reference and const members
ConstRef::ConstRef(int ii) : i(ii), ci(ii), ri(i) {}

// class X
// {
// public:
//     X(int a = 0);
//     X(int a = 0, int b = 1);
// };

// exercises
struct X
{
    X(int i, int j) : base(i), rem(base % j) {}
    int rem, base;
};
// Delegating Constructors
class Sales_data
{
public:
    // nondelegating constructor initializes members from corresponding arguments
    // When a constructor delegates to another constructor, the constructor initializer list and function body of the delegated-to constructor are both executed
    Sales_data(std::string s, unsigned cnt, double price) : bookNo(s), units_sold(cnt), revenue(cnt * price) { cout << "the delegated-to constructor constructor body executed!" << endl; }
    // remaining constructors all delegate to another constructor
    Sales_data() : Sales_data("", 0, 0) {}
    Sales_data(std::string s) : Sales_data(s, 0, 0) { cout << "the delegating constructor executed!" << endl; }
    Sales_data(std::istream &is) : Sales_data()
    {
        read(is, *this);
    }

    // We can prevent the use of a constructor in a context that requires an implicit conversion by declaring the constructor as explicit
    // Constructors that require more arguments are not used to perform an implicit conversion, so there is no need to designate such constructors as explicit.

    // explicit Sales_data(std::string s) : Sales_data(s, 0, 0) { cout << "the delegating constructor executed!" << endl; }
    // explicit Sales_data(std::istream &is) : Sales_data()
    // {
    //     read(is, *this);
    // }

    // other members as before

    void combine(const Sales_data &);

private:
    void read(std::istream &is, Sales_data &s) {}
    string bookNo;
    unsigned units_sold;
    double revenue;
};

void Sales_data::combine(const Sales_data &) {}

// default constructor
// What may be less obvious is the impact on classes that have data members that do not have a default constructor
class NoDefault
{
public:
    NoDefault(const std::string &);
    // additional members follow, but no other constructors
    // exercises
    // Assume we have a class named NoDefault that has a constructor that takes an int, but has no default constructor. Define a class C that has a member of type NoDefault. Define the default constructor for C.
    NoDefault(int);
};

NoDefault::NoDefault(int a) {}

class C
{
public:
    C() : mem(10) {}

private:
    NoDefault mem;
};

C c;

// vector<NoDefault> vec(10); // error: no matching function for call to 'NoDefault::NoDefault()'

// What if we defined the vector in the previous execercise to hold objects of type C?
vector<C> vec(10);

struct A
{ // my_mem is public by default;
  // 没有默认构造函数会影响上下文
  // NoDefault my_mem;
};
A a; //  error: cannot synthesize a constructor for A
struct B
{

    B() {} //  error: no initializer for b_member
    // 没有默认构造函数会影响上下文
    // NoDefault b_member;
};

//  Literal Classes
class Debug
{
public:
    // a constexpr constructor must meet the requirements of a constructor—meaning it can have no return statement—and of a constexpr function—meaning the only executable statement it can have is a return statement
    constexpr Debug(bool b = true) : hw(b), io(b), other(b) { /*cout << b << endl;*/ }
    constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {}
    constexpr bool any() const { return hw || io || other; }
    void set_io(bool b) { io = b; }
    void set_hw(bool b) { hw = b; }
    void set_other(bool b) { hw = b; }

private:
    bool hw;    // hardware errors other than IO errors
    bool io;    // IO errors
    bool other; // other errors
};

int main()
{
    Sales_data s("a");

    // Using the Default Constructor
    Sales_data obj(); // ok: but defines a function, not an object

    // The problem is that, although we intended to declare a default-initialized object, obj actually declares a function taking no parameters and returning an object of type Sales_data.
    /*
    if (obj.isbn() == Primer_5th_ed.isbn()) // error: obj is a function
    */

    //  the compiler automatically creates a Sales_data object from the given string
    Sales_data item;
    string null_book = "9-999-99999-9";
    // constructs a temporary Sales_data object
    // with units_sold and revenue equal to 0 and bookNo equal to null_book
    item.combine(null_book);

    // Only One Class-Type Conversion Is Allowed
    // In we noted that the compiler will automatically apply only one class-type conversion
    // error: requires two user-defined conversions:
    //    (1) convert "9-999-99999-9" to string
    //    (2) convert that (temporary) string to Sales_data
    // item.combine("9-999-99999-9");

    // ok: explicit conversion to string, implicit conversion to Sales_data
    item.combine(string("9-999-99999-9"));
    // ok: implicit conversion to string, explicit conversion to Sales_data
    item.combine(Sales_data("9-999-99999-9"));

    // his Sales_data object is a temporary. We have no access to it once combine finishes. Effectively, we have constructed an object that is discarded after we add its value into item
    // uses the istream constructor to build an object to pass to combine
    item.combine(cin);

    // exercises
    {
        string null_isbn("9-999-99999-9");
        Sales_data item1(null_isbn);
        Sales_data item2("9-999-99999-9");
    }

    constexpr Debug io_sub(false, true, false); // debugging IO
    if (io_sub.any())                           // equivalent to if(true)
        cerr << "print appropriate error messages" << endl;
    constexpr Debug prod(false); // no debugging during production
    if (prod.any())              // equivalent to if(false)
        cerr << "print an error message" << endl;
    return 0;
}