#include <iostream>
using std::cout;
using std::endl;

// 重载main函数
// class A
// {
// private:

// public:

// };

// int main(A);
// int main(A a)
// {
//     cout<<"overloaded main"<<endl;
//     return 0;
// }

// main 函数不能重载
//  int main(int a);
//  int main(double b);

int main(void)
{
    // It is an error for two functions to differ only in terms of their return types. If the parameter lists of two functions match but the return types differ, then the second declaration is an error
    int func(void);
    // bool func(void); // error.两个函数只有返回类型不一样 而形参的类型和个数都是一样的
    bool func(int); // 函数的返回类型和形参列表都不一样

    // Because there is no conversion from const, we can pass a const object (or a pointer to const) only to the version with a const parameter. 带有low-level const的参数传入的时候没有转换成没有const的类型的办法，因此它只能使用带有const的版本
    // Because there is a conversion to const, we can call either function on a nonconst object or a pointer to nonconst.没有const的参数两个版本的函数都可以使用
    // However, the compiler will prefer the nonconst versions when we pass a nonconst object or pointer to nonconst.
    int lookup(int);
    int lookup(const int); // redeclares int lookup(int)

    int lookup(int *);
    int lookup(int *const); // redeclares int lookup(int*)

    int lookup(int &);
    int lookup(const int &);
    return 0;
}