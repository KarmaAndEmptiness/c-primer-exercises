#include <iostream>
using std::cout;
using std::endl;
int main()
{
    // Comma operator. Binary operator that is evaluated left to right. The result of a comma expression is the value of the right-hand operand.
    int a = 1, b = 2;
    int result = (a = 3, b = 4);
    cout << "result: " << result << "  " // 4
         << "a: " << a << "  "
         << endl;

    //  The result is an lvalue if and only if that operand is an lvalue.
    int c = 10, d = 20;
    (c, d) = 30;
    cout << "c: " << c << "  " // 10
         << "d: " << d << "  " // 30
         << endl;

    {
        int a = 10, b = 20;
        (a < b ? a : b) = 30; // 正确，三元表达式的返回结果是左值
        cout << "a: " << a << "  "
             << "b: " << b << "  "
             << endl;
    }

    {
        int a = 10, b = 20;
        (a > b ? a : b) = 30;
        cout << "a: " << a << " "
             << "b: " << b << "  "
             << endl;
    }
    return 0;
}