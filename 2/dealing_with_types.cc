#include <iostream>
#include "../Sales_item.h"
int main()
{
    typedef double wages;   // wages is a synonym for double
    typedef wages base, *p; // base is a synonym for double, p for double*

    // The new standard introduced a second way to define a type alias, via an alias declaration:
    using SI = Sales_item; // SI is a synonym for Sales_item

    // Declarations that use type aliases that represent compound types and const can yield surprising results.
    typedef char *pstring;
    const pstring cstr = 0; // 一个const指针 cstr is a constant pointer to char
    // pstring const cstr = "1";//等价于上面的
    // *cstr="2";

    const pstring *ps; // 指向一个const指针的object  ps is a pointer to a constant pointer to char.The type of pstring is “pointer to char.” So, const pstring is a constant pointer to char—not a pointer to const char.
    // pstring const *ps;//等价于上面的

    // const char *cstr = 0; //指向一个const char的指针  wrong interpretation of const pstring cstr

    int i = 11;
    const int ci = i, &cr = ci;
    auto b = ci;  // b is an int (top-level const in ci is dropped)
    auto c = cr;  // c is an int (cr is an alias for ci whose const is top-level)
    auto d = &i;  // d is an int*(& of an int object is int*)
    auto e = &ci; // e is const int*(& of a const object is low-level const)
    int a = 12;
    // *e = a;

    auto &g = ci; // g is a const int& that is bound to ci
    // auto &h = 42;       // error: we can't bind a plain reference to a literal
    const auto &j = 42; // ok: we can bind a const reference to a literal

    auto k = ci, &l = i;     // k is int; l is int&
    auto &m = ci, *p2 = &ci; // m is a const int&;p2 is a pointer to const int
    // error: type deduced from i is int; type deduced from &ci is const int
    // auto &n = i, *p2 = &ci;

    // exercise
    a = 42;
    b = 42;
    c = 42;
    // d = 42;
    // e = 42;
    // g = 42;

    const int i1 = 42;            // const int
    auto j1 = i1;                 // const int
    const auto &k1 = i1;          // const int &const k1
    auto *p1 = &i1;               // const int *p1
    const auto j2 = i1, &k2 = i1; // const int const j2,const &k2

    // j2=1;
    // k2=1;

    // *p=1;
    // k1 = 1;

    // j=1;

    // decltype(f()) sum = x; // sum has whatever type f returns.Here, the compiler does not call f, but it uses the type that such a call would return as the type for sum.

    const int ci0 = 0, &cj = ci;
    decltype(ci0) x = 0; // x has type const int
    decltype(cj) y = x;  // y has type const int& and is bound to x
    // decltype(cj) z;     // error: z is a reference and must be initialized

    // decltype of an expression can be a reference type
    int i0 = 42, *p0 = &i0, &r = i0;
    decltype(r + 0) b0; // ok: addition yields an int; b0 is an (uninitialized) int
    // decltype(*p) c;     // error: c is int& and must be initialized.As we’ve seen, when we dereference a pointer, we get the object to which the pointer points. Moreover, we can assign to that object. Thus, the type deduced by decltype(*p) is int&, not plain int.

    // decltype of a parenthesized variable is always a reference
    decltype(i0) d0;
    // decltype((i)) e; // error: e is int& and must be initialized
    // decltype(r) e; // const int & reference.Remember that decltype((variable)) (note, double parentheses) is always a reference type, but decltype(variable) is a reference type only if variable is a reference.

    // exercise
    int a1 = 3, b1 = 4;     // int
    decltype(a1) c1 = a1;   // a is a variable so it is an int
    decltype((b1)) d1 = a1; //(b) is an expression so it is an int &
    ++c1;
    ++d1;
    std::cout << "a1: " << a1 << "  b1: " << b1 << "  c1: " << c1 << "  d1: " << d1 << std::endl;

    int a2 = 3, b2 = 4;
    decltype(a2) c2 = a2;
    decltype(a2 = b2) d2 = a2; // Assignment is an example of an expression that yields a reference type. The type is a reference to the type of the left-hand operand. That is, if i is an int, then the type of the expression i = x is int&.
    d2++;
    std::cout << "a2: " << a2 << "  b2:" << b2 << "  c2: " << c2 << "  d2: " << d2 << std::endl;

    // Describe the differences in type deduction between decltype and auto. Give an example of an expression where auto and decltype will deduce the same type and an example where they will deduce differing types.
    int a3 = 0, *p3 = &a3;
    auto b3 = *p3;         // auto deduces to int
    decltype(*p3) c3 = a3; // decltype deduces to int &
    c3++;
    std::cout << "a3: " << a3 << "  b3: " << b3 << "  c3:" << c3 << std::endl;

    return 0;
}