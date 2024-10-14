#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
int next_num()
{
    return 1;
}
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

    int a = 1;
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

    switch (a)
    {
    case 1:
        // this switch statement is illegal because these initializations might be bypassed
        // string file_name; // error: control bypasses an implicitly initialized variable
        // int ival = 0;     // error: control bypasses an explicitly initialized variable
        int jval; // ok: because jval is not initialized
        break;
    case 2:
        // file_name = "hello";
        // ival = 10;
        // ok: jval is in scope but is uninitialized
        jval = next_num(); // ok: assign a value to jval
        // if (file_name.empty()) // file_name is in scope but wasn't initialized
        break;

    default:
        break;
    }

    switch (a)
    {
    case 1:
        // int ival = 0; // 在case 1中初始化为0
        break;
    case 2:
        // ival = 10; // 编译器报错：ival可能未初始化
        break;
    default:
        break;
    }

    // exercise
    ch = 'a';
    switch (toupper(ch)) // both a and A as same
    {
    case 'A':
        cout << ch << endl;
        break;

    default:
        break;
    }

    return 0;
}