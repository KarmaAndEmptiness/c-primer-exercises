#include <iostream>
int t = 0;
int main()
{
    int i = 42;
    const int &r1 = i;      // we can bind a const int& to a plain int object
    const int &r2 = 42;     // ok: r2 is a reference to const
    const int &r3 = r1 * 2; // ok: r3 is a reference to const
    // int &r4 = 2;        // error: r4 is a plain, non const reference
    std::cout << "&r2: " << (&r2) << std::endl;

    int &r4 = i; // r1 bound to i
    r4 = 0;      // r4 is not const; i is now 0
    // r2 = 0;            // error: r2 is a reference to const

    double a = 3.14;
    const int &b = a;
    std::cout << "&b: " << (&b) << "  &a: " << (&a) << "  b: " << b << std::endl;

    int c = 2;
    // constexpr int *pc = &c;//不能在编译时确定 variables defined inside a function ordinarily are not stored at a fixed address.
    int *const pc = &c;

    constexpr int *pt = &t; // the address of an object defined outside of any function is a constant expression, and so may be used to initialize a constexpr pointer.

    static int d = 3;       // that functions may define variables that exist across calls to that function
    constexpr int *pd = &d; // Like an object defined outside any function, these special local objects also have fixed addresses.

    const int *p = nullptr;     // p is a pointer to a const int
    constexpr int *q = nullptr; // q is a const pointer to int

    // excercise
    int null = 0, *p = &null;
    return 0;
}