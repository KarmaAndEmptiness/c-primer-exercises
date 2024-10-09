#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main()
{
    // If the left-hand operand is of a built-in type, the initializer list may contain at most one value, and that value must not require a narrowing conversion
    int k = 0;
    // k = {3.14}; // error: narrowing conversion

    // Regardless of the type of the left-hand operand, the initializer list may be empty. In this case, the compiler generates a value-initialized temporary and assigns that value to the left-hand operand.
    vector<int> vec = {};

    // Assignment Is Right Associative
    {
        int ival, jval;
        ival = jval = 0; // ok: each assigned 0
    }

    // Each object in a multiple assignment must have the same type as its right-hand neighbor or a type to which that neighbor can be converted
    int ival, *pval; // ival is an int; pval is a pointer to int
    // ival = pval = 0; // error: cannot assign the value of a pointer to an int
    string s1, s2;
    s1 = s2 = "OK"; // string literal "OK" converted to string

    int i = 1, j = 0;

    if (i = j)
        ;

    return 0;
}