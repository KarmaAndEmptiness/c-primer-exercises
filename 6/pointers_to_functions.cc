#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
int main()
{
    // compares lengths of two strings
    bool lengthCompare(const string &, const string &); // has type bool(const string&, const string&).
    // To declare a pointer that can point at this function, we declare a pointer in place of the function name
    // pf points to a function returning bool that takes two const string references
    // The parentheses around *pf are necessary. If we omit the parentheses, then we declare pf as a function that returns a pointer to bool
    bool (*pf)(const string &, const string &); // uninitialized
    pf = lengthCompare;                         // pf now points to the function named lengthCompare
    pf = &lengthCompare;                        // equivalent assignment: address-of operator is optional

    bool b1 = pf("hello", "goodbye");            // calls lengthCompare
    bool b2 = (*pf)("hello", "goodbye");         // equivalent call
    bool b3 = lengthCompare("hello", "goodbye"); // equivalent call

    string::size_type sumLength(const string &, const string &);
    bool cstringCompare(const char *, const char *);
    pf = 0; // ok: pf points to no function
    // pf = sumLength;      // error: return type differs
    // pf = cstringCompare; // error: parameter types differ
    pf = lengthCompare; // ok: function and pointer types match exactly

    // Pointers to Overloaded Functions
    void ff(int *);
    void ff(unsigned int);
    void (*pf1)(unsigned int) = ff; // pf1 points to ff(unsigned)

    // void (*pf2)(int) = ff;    // error: no ff with a matching parameter list
    // double (*pf3)(int*) = ff; // error: return type of ff and pf3 don't match

    // Function Pointer Parameters
    // third parameter is a function type and is automatically treated as a pointer to function
    void useBigger(const string &s1, const string &s2,
                   bool pf(const string &, const string &));
    // equivalent declaration: explicitly define the parameter as a pointer to function
    void useBigger(const string &s1, const string &s2,
                   bool (*pf)(const string &, const string &));

    // Func and Func2 have function type
    typedef bool Func(const string &, const string &);
    typedef decltype(lengthCompare) Func2; // equivalent type

    // FuncP and FuncP2 have pointer to function type
    typedef bool (*FuncP)(const string &, const string &);
    typedef decltype(lengthCompare) *FuncP2; // equivalent type
    return 0;
}
string::size_type sumLength(const string &, const string &) { return 0; }
bool cstringCompare(const char *, const char *) { return 0; }
bool lengthCompare(const string &, const string &) { return 0; }
