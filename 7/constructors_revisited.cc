#include <iostream>
using std::cout;
using std::endl;

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
int main()
{

    return 0;
}