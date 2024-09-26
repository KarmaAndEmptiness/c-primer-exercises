#include <iostream>
int main()
{
    unsigned u = 10;
    int i = -42;
    int j = 4294967295;
    unsigned a = 4294967295;
    a++;
    std::cout << i + i << std::endl; // prints -84
    std::cout << u + i << std::endl; // if 32-bit ints, prints 4294967264
    std::cout << j << std::endl;
    std::cout << a << std::endl;
    unsigned u1 = 42, u2 = 10;
    std::cout << u1 - u2 << std::endl; // ok: result is 32
    std::cout << u2 - u1 << std::endl; // ok: but the result will wrap around
    u2 = 42;
    std::cout << u2 - u << std::endl;
    std::cout << u - u2 << std::endl;

    i = 10;
    int i2 = 42;
    std::cout << i2 - i << std::endl;
    std::cout << i - i2 << std::endl;

    std::cout << i - u << std::endl;
    std::cout << u - i << std::endl;
    return 0;
}