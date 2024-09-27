#include <iostream>
int main()
{
    int iVal = 1024; // 如何把iVal这个名字绑定到另一个object上呢？&iVal=&temp吗? 这个object的名字不能操作 只能用定义一个新的名字引用这个object
    int temp = 1;
    int &refVal = iVal;
    refVal = temp; // 这里没有任何效果 Because there is no way to rebind a reference, references must be initialized.Because references are not objects, we may not define a reference to a reference.
    iVal = 20;

    // int &test=20;//不行,error: initializer must be an object
    // double dval = 3.14;
    // int &refVal5 = dval; // error: initializer must be an int object

    std::cout << "iVal: " << iVal << "  refVal: " << refVal << "  &iVal==&refVal: " << (&iVal == &refVal) << "  &refVal: " << &refVal << std::endl;

    // We can define multiple references in a single definition. Each identifier that is a reference must be preceded by the & symbol:
    int i = 1024, i2 = 2048; // i and i2 are both ints
    int &r = i, r2 = i2;     // r is a reference bound to i; r2 is an int
    int i3 = 1024, &ri = i3; // i3 is an int; ri is a reference bound to i3
    int &r3 = i3, &r4 = i2;  // both r3 and r4 are references

    // exercise
    int a, &ra = a;
    a = 5;
    a = 10;
    std::cout << a << " " << ra << std::endl;

    // The * must be repeated for each pointer variable:
    int *ip1, *ip2;  // both ip1 and ip2 are pointers to int
    double dp, *dp2; // dp2 is a pointer to double; dp is a double

    // Some symbols, such as & and *, are used as both an operator in an expression and as part of a declaration. The context in which a symbol is used determines what the symbol means:
    int b = 42;
    int &rb = b;   // & follows a type and is part of a declaration; rb is a reference
    int *p;        // * follows a type and is part of a declaration; p is a pointer
    p = &b;        // & is used in an expression as the address-of operator
    *p = b;        // * is used in an expression as the dereference operator
    int &rb1 = *p; // & is part of the declaration; * is the dereference operator

    // There are several ways to obtain a null pointer:
    int *p1 = nullptr; // equivalent to int *p1 = 0;
    int *p2 = 0;       // directly initializes p2 from the literal constant 0
    // must #include cstdlib
    int *p3 = NULL; // equivalent to int *p3 = 0;

    // int zero = 0;
    // pi = zero;        // error: cannot assign an int to a pointer

    // Like any other pointer, a void* pointer holds an address, but the type of the object at that address is unknown:
    double obj = 3.14, *pd = &obj;
    // ok: void* can hold the address value of any data pointer type
    void *pv = &obj; // obj can be an object of any type

    pv = pd; // pv can hold a pointer to any type

    // 由于 void* 不知道指向的数据类型，它不能直接进行数据访问或操作。要访问存储在 void* 指针中的数据，我们必须先将它转换（cast）为具体类型的指针，然后才能进行解引用或操作
    // *pv=2;//不行，We cannot use a void* to operate on the object it addresses—we don’t know that object’s type, and the type determines what operations we can perform on the object.
}