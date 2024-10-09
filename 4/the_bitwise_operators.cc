#include <iostream>
using std::cout;
using std::endl;
int main()
{
    // The illustrations have the low-order bit on the right
    // These examples assume char has 8 bits, and int has 32

    unsigned char bits = 0233;
    // 10011011
    // 0233 is an octal literal

    // The left-shift operator (the <<operator) inserts 0-valued bits on the right.
    bits << 8;
    // 00000000 00000000 10011011 00000000
    // bits promoted to int and then shifted left by 8 bits

    bits << 31;
    // 10000000 00000000 00000000 00000000
    // left shift 31 bits, left-most bits discarded

    // The behavior of the right-shift operator (the >>operator) depends on the type of the left-hand operand: If that operand is unsigned, then the operator inserts 0-valued bits on the left; if it is a signed type, the result is implementation defined—either copies of the sign bit or 0-valued bits are inserted on the left.
    bits >> 3;
    // 00000000 00000000 00000000 00010011
    // Right shift 3 bits, 3 right-most bits discarded

    unsigned char bits = 0227; // 10010111
    ~bits;                     // 11111111 11111111 11111111 01101000

    unsigned char b1 = 0145; // 01100101
    unsigned char b2 = 0257; // 10101111

    b1 & b2; // 00000000 00000000 00000000 00100101
    b1 | b2; // 00000000 00000000 00000000 11101111
    b1 ^ b2; // 00000000 00000000 00000000 11001010

    cout << 42 + 10;   // ok: + has higher precedence, so the sum is printed
    cout << (10 < 42); // ok: parentheses force intended grouping; prints 1
    // cout << 10 < 42;   // error: attempt to compare cout to 42!
    1UL << 27 // generate a value with only bit number 27 set
        return 0;
}