#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>
using std::cout;
using std::endl;
using std::initializer_list;
using std::string;
using std::vector;
class LargeObject
{
public:
    int data[1000]; // 假设有一个很大的数组
};
// // the reference parameter occurs counts how often c occurs
string::size_type find_cchar(const string &s, char c,
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
int main(int argc, char *argv[]) // argc接收的是option的个数，argv[0]是程序名，argv[1]及之后的存的是option字符串
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
    cout << "find_char(s,'o',ctr): " << find_cchar(s, 'o', ctr) << "  ctr: " << ctr << endl;

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

    bool is_sentence(const string &);
    cout << "is_sentence(\"hello,world.\"): " << is_sentence("hello,world.") << endl;
    cout << "is_sentence(\"hello,world\"): " << is_sentence("hello,world") << endl;

    // exercise
    //  Write declarations for each of the following functions. When you write these declarations, use the name of the function to indicate what the function does.

    // (a) A function named compare that returns a bool and has two parameters that are references to a class named matrix.
    class maritx
    {
    };

    bool compare(maritx &, maritx &);
    // (b) A function named change_val that returns a vector<int> iterator and takes two parameters: One is an int and the other is an iterator for a vector<int>.
    vector<int>::iterator change_val(int, vector<int>::iterator);

    // despite appearances, these three declarations of print are equivalent
    // each function has a single parameter of type const int*
    void print(const int *);   // 一个指向int类型的元素的指针。传入函数的是数组的第一个元素的指针
    void print(const int[]);   // shows the intent that the function takes an array
    void print(const int[10]); // 这个函数只能传入一个size为10的int类型的数组 dimension for documentation purposes (at best)

    // matrix points to the first element in an array whose elements are arrays of ten ints
    void print(int(*matrix)[10], int rowSize); // 一个指针指向一个size为10的int类型的数组。 因为数组传入的是第一个元素的指针，所以二维数组传入的是它当中第一个数组的指针
    // equivalent definition
    void print(int matrix[][10], int rowSize);

    // Functions with Varying Parameters
    //  We can write a function that takes an unknown number of arguments of a single type by using an initializer_list parameter.
    void error_msg(initializer_list<string> il); // Unlike vector, the elements in an initializer_list are always const values; there is no way to change the value of an element in an initializer_list.

    error_msg({"a", "b"}); // When we pass a sequence of values to an initializer_list parameter, we must enclose the sequence in curly braces:

    enum ErrCode
    {

    };
    void error_msg(ErrCode e, initializer_list<string> il);

    // Ellipsis Parameters
    // Ellipsis parameters should be used only for types that are common to both C and C++. In particular, objects of most class types are not copied properly when passed to an ellipsis parameter.
    // An ellipsis parameter may appear only as the last element in a parameter list and may take either of two forms:
    using T = int;
    void foo(/*parm_list*/ initializer_list<T>, ...); // 这里的pqrm_list只是举个例子
    void foo(...);

    return 0;
}
void foo(...)
{
}

void error_msg(initializer_list<string> il)
{
    for (auto beg = il.begin(); beg != il.end(); ++beg)
        cout << *beg << " ";
    cout << endl;
}

// ok: parameter is a reference to an array; the dimension is part of the type
void print(int (&arr)[10])
{
    for (auto elem : arr)
        cout << elem << endl;
}
string::size_type find_char(string &s, char c,
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
    return ret;
}
bool is_sentence(const string &s)
{
    // if there's a single period at the end of s, then s is a sentence
    string::size_type ctr = 0;
    string str = s;

    // The right way to fix this problem is to fix the parameter in find_char. If it’s not possible to change find_char, then define a local string copy of s inside is_sentence and pass that string to find_char.
    return find_char(str, '.', ctr) == s.size() - 1 && ctr == 1;
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