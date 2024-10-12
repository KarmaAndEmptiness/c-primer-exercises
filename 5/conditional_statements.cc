#include <iostream>
using std::cout;
using std::endl;
char getVal()
{
    return 'a';
}
int main()
{
    // case labels must be integral constant expressions
    char ch = getVal();
    // int ival = 42;
    // switch (ch)
    // {
    // case 3.14: // error: noninteger as case label
    // case ival: // error: nonconstant as case label
    //     // . . .
    // }

    double d = 3.14;
    // switch (d)
    // {
    // case 3.14:

    //     break;

    // default:
    //     break;
    // }

    constexpr int a = 1;
    int b = 1;
    switch (a)
    {
    case 2:
        break;
    // case b:
    //     break;
    // case 2: // It is an error for any two case labels to have the same value.
    //     break;
    default:
        break;
    }

    // Here we stacked several case labels together with no intervening break. The same code will be executed whenever ch is a vowel.
    unsigned vowelCnt = 0;
    // ...
    switch (ch)
    {
    // any occurrence of a, e, i, o, or u increments vowelCnt
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        ++vowelCnt;
        break;
    }

    return 0;
}