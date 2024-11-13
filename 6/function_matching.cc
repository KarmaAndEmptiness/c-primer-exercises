#include <iostream>
using std::cout;
using std::endl;
int main()
{
    // it is not so simple when the overloaded functions have the same number of parameters and when one or more of the parameters have types that are related by conversions
    void f();
    void f(int);
    void f(int, int);
    void f(double, double = 3.14);
    // In our case, there is only one (explicit) argument in the call. That argument has type double. To call f(int), the argument would have to be converted from double to int. The other viable function, f(double, double), is an exact match for this argument. An exact match is better than a match that requires a conversion. Therefore, the compiler will resolve the call f(5.6) as a call to the function that has two double parameters.

    f(5.6); // calls void f(double, double)

    //  In this case, the viable functions are f(int, int) and f(double, double).
    // f(42, 2.56);//The compiler will complain that the call is ambiguous.

    // exercises
    f(42);

    // Matches Requiring Promotion or Arithmetic Conversion
    void ff(int);
    void ff(short);
    ff('a'); // char promotes to int; calls f(int)

    // All the arithmetic conversions are treated as equivalent to each other.
    void manip(long);
    void manip(float);
    // The literal 3.14 is a double. That type can be converted to either long or float. Because there are two possible arithmetic conversions, the call is ambiguous.

    // manip(3.14); // error: ambiguous call

    // Function Matching and const Arguments
    void fff(const int &a);
    void fff(int &a);

    const int b = 0;
    int c = 1;
    fff(b); // calls void fff(const int &a)
    fff(c); // calls void fff(int &a)

    return 0;
}
void fff(const int &a) {}
void fff(int &a) {}
void manip(long) {}
void manip(float) {}
void f()
{
}
void f(int) {}
void f(int, int) {}
void f(double, double = 3.14) {}
void ff(int) {}
void ff(short) {}