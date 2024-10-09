#include <iostream>
using std::cout;
using std::endl;
int main()
{
    int ival = 42;
    double dval = 3.14;
    ival % 12; // ok: result is 6

    // 在 C++ 中，运算符 % 是 取模运算符，它只能用于整数类型的操作数，而不能用于浮点数。
    // ival % dval; // error: floating-point operand

    21 % 6;   /*  result is 3  */
    21 / 6;   /*  result is 3   */
    21 % 7;   /*  result is 0  */
    21 / 7;   /*  result is 3   */
    -21 % -8; /*  result is  -5 */
    -21 / -8; /*  result is 2   */
    21 % -5;  /*  result is 1  */
    21 / -5;  /*  result is  -4  */

        // exercise
    cout << 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2 << endl;
    return 0;
}