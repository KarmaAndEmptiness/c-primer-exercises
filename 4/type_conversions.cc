#include <iostream>
using std::cout;
using std::endl;
int main()
{
    auto a = 3.14;
    // in most expressions, values of integral types smaller than int are first promoted to an appropriate larger integral type.
    short b = 1;
    short c = 2;
    auto d = b + c; // short类型比int类型更小，所以把short类型转换成了int类型
    cout << "sizeof a : " << sizeof a << "  "
         << "sizeof(float): " << sizeof(float) << "  "
         << "sizeof(unsigned long long): " << sizeof(unsigned long long) << "  "
         << "sizeof 3.14f : " << sizeof 3.14f << "  "
         << "sizeof 2ULL : " << sizeof 2ULL << "  "
         // The rules define a hierarchy of type conversions in which operands to an operator are converted to the widest type.
         << "sizeof(3.14f+2ULL): " << sizeof(3.14f + 2ULL) << "  " // 这里没有把float类型转换成unsigned long long类型。More generally, in expressions that mix floating-point and integral values, the integral value is converted to an appropriate floating-point type.
         << "sizeof d: " << sizeof d << endl;

    return 0;
}