#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;
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

    // Returning a Pointer to Function
    using F = int(int *, int);      // F is a function type, not a pointer
    using PF = int (*)(int *, int); // PF is a pointer type

    PF f1(int); // ok: PF is a pointer to function; f1 returns a pointer to function
    // F f1(int);  // error: F is a function type; f1 can't return a function
    F *f1(int); // ok: explicitly specify that the return type is a pointer to function

    // Reading this declaration from the inside out, we see that f1 has a parameter list, so f1 is a function. f1 is preceded by a * so f1 returns a pointer. The type of that pointer itself has a parameter list, so the pointer points to a function. That function returns an int.
    int (*f1(int))(int *, int);

    // For completeness, it’s worth noting that we can simplify declarations of functions that return pointers to function by using a trailing return
    auto f1(int) -> int (*)(int *, int);

    // Using auto or decltype for Function Pointer Types
    string::size_type sumLength(const string &, const string &);
    string::size_type largerLength(const string &, const string &);

    // depending on the value of its string parameter,
    // getFcn returns a pointer to sumLength or to largerLength
    decltype(sumLength) *getFcn(const string &);

    // exercises
    //  Write a declaration for a function that takes two int parameters and returns an int, and declare a vector whose elements have this function pointer type.
    int func(int, int);
    vector<decltype(func) *> funcs;
    vector<int (*)(int, int)> funcs1;

    // Write four functions that add, subtract, multiply, and divide two int values. Store pointers to these values in your vector from the previous exercise.
    int add(int, int);
    int subtract(int, int);
    int multiply(int, int);
    int divide(int, int);
    funcs.push_back(add);
    funcs.push_back(subtract);
    funcs.push_back(multiply);
    funcs.push_back(divide);

    funcs1.push_back(add);
    funcs1.push_back(subtract);
    funcs1.push_back(multiply);
    funcs1.push_back(divide);

    // Call each element in the vector and print their result.

    for (auto &&func : funcs)
    {
        cout << func(2, 1) << " ";
    }
    cout << endl;

    for (auto &&func : funcs1)
    {
        cout << func(2, 1) << " ";
    }
    cout << endl;

    return 0;
}
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }
void ff(int *) {}
void ff(unsigned int) {}
string::size_type sumLength(const string &, const string &) { return 0; }
bool cstringCompare(const char *, const char *) { return 0; }
bool lengthCompare(const string &, const string &) { return 0; }
