#include <iostream>
#include "Sales_item.h"
int main()
{
    typedef double wages;   // wages is a synonym for double
    typedef wages base, *p; // base is a synonym for double, p for double*

    // The new standard introduced a second way to define a type alias, via an alias declaration:
    using SI = Sales_item; // SI is a synonym for Sales_item

    // Declarations that use type aliases that represent compound types and const can yield surprising results.
    typedef char *pstring;
    const pstring cstr = 0; // 一个const指针 cstr is a constant pointer to char
    const pstring *ps;      // 指向一个const指针的object  ps is a pointer to a constant pointer to char.The type of pstring is “pointer to char.” So, const pstring is a constant pointer to char—not a pointer to const char.

    // const char *cstr = 0; //指向一个const char的指针  wrong interpretation of const pstring cstr
    return 0;
}