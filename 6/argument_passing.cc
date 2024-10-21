#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
class LargeObject
{
public:
    int data[1000]; // 假设有一个很大的数组
};
// // the reference parameter occurs counts how often c occurs
string::size_type find_char(const string &s, char c,
                            string::size_type &occurs)
{
    auto ret = s.size(); // 将ret置于一个不可能是索引的位置，便于后面记录目标字符第一次出现的位置的索引 position of the first occurrence, if any
    occurs = 0;          // set the occurrence count parameter
    for (decltype(ret) i = 0; i != s.size(); ++i)
    {
        if (s[i] == c)
        {
            if (ret == s.size()) // 如果没有更改过，则记录该位置的索引
                ret = i;         // remember the first occurrence of c
            ++occurs;            // increment the occurrence count
        }
    }
    return ret; // count is returned implicitly in occurs
}
int main()
{
    // If the parameter is a reference, then the parameter is bound to its argument.
    void r_func(int &); // 它的形参接收一个左值
    void i_func(int);   // 它的形参接收一个整型的值
    // func(1); // 这里不能直接传入一个右值
    int a = 10;
    r_func(a);
    i_func(1); // 这里可以传入一个右值

    void reset(int *);
    int i = 2;
    reset(&i);
    cout << "i: " << i << endl;

    // Using pointers, write a function to swap the values of two ints. Test the function by calling it and printing the swapped values.
    void swap_pi(int *, int *);
    void swap_ri(int &, int &);
    int b = 20;
    swap_pi(&a, &b);
    cout << "a: " << a << "  b: " << b << endl;
    swap_ri(a, b);
    cout << "a: " << a << "  b: " << b << endl;

    string::size_type ctr = 0;
    string s = "hello,world";
    cout << "find_char(s,'o',ctr): " << find_char(s, 'o', ctr) << "  ctr: " << ctr << endl;

    // Give an example of when a parameter should be a reference type. Give an example of when a parameter should not be a reference.
    // class LargeObject
    // {
    // public:
    //     int data[1000]; // 假设有一个很大的数组
    // };
    void processObject(LargeObject &); // 在这个例子中，LargeObject 是一个包含大量数据的对象。通过引用传递对象 obj，可以避免拷贝整个对象，提高程序效率，并允许函数内部修改原始对象。

    void increment(int); // 在这个例子中，increment 函数中传递的是 x 的副本，并不会改变原始值。如果我们不希望函数改变传入的参数，或者处理的对象很小（如基本数据类型 int），那么可以不使用引用。

    // In C++, we can define several different functions that have the same name. However, we can do so only if their parameter lists are sufficiently different.
    void fcn(const int);
    // void fcn(int);//error

    // We can initialize an object with a low-level const from a nonconst object but not vice versa, and a plain reference must be initialized from an object of the same type.
    const int j = 22;    // top-level const
    const int *pci = &j; // low-level const
    const int &rci = j;  // low-level const
    // int *pi = pci;       // error: types of pi and pci don't match
    // int &ri = rci; // error: types of ri and rci don't match
    return 0;
}

// In C++, we can define several different functions that have the same name. However, we can do so only if their parameter lists are sufficiently different.
void fcn(const int i) { /* fcn can read but not write to i */ }
// void fcn(int i) { /* . . . */ } // error: redefines fcn(int)
void processObject(LargeObject &obj)
{
    // 处理大型对象，不需要拷贝
    obj.data[0] = 10; // 修改原始对象
}

void increment(int num)
{
    num++; // 只是增加副本的值
}

void r_func(int &a)
{
    cout << "a: " << a << endl;
}

void i_func(int a)
{
    cout << "a: " << a << endl;
}

// function that takes a pointer and sets the pointed-to value to zero
void reset(int *ip)
{
    *ip = 0; // changes the value of the object to which ip points
    ip = 0;  // changes only the local copy of ip; the argument is unchanged
}

void swap_pi(int *a, int *b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}
void swap_ri(int &a, int &b)
{
    int temp = 0;
    temp = a;
    a = b;
    b = temp;
}