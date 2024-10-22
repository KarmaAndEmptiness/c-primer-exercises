#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

int *func1(int a)
{
    return nullptr;
}

char &get_val(string &str, string::size_type ix)
{
    return str[ix]; // get_val assumes the given index is valid
}
void print_vector(vector<int>::iterator it, vector<int>::const_iterator end)
{
    if (it == end)
        return;
    cout << *it << " ";
    print_vector(++it, end);
}
int main()
{
    // Reference Returns Are Lvalues
    // In particular, we can assign to the result of a function that returns a reference to nonconst
    string s("a value");
    cout << s << endl;   // prints a value
    get_val(s, 0) = 'A'; // changes s[0] to A
    cout << s << endl;   // prints A value

    // There is one exception to the rule that a function with a return type other than void must return a value: The main function is allowed to terminate without a return. If control reaches the end of main and there is no return, then the compiler implicitly inserts a return of 0.
    // return 0;

    // To make return values machine independent, the cstdlib header defines two preprocessor variables that we can use to indicate success or failure
    // return EXIT_SUCCESS;
    // return EXIT_FAILURE;

    // The main function may not call itself.
    // main(); // 进入死循环

    // exercise
    //  Write a recursive function to print the contents of a vector.
    vector<int> vec = {1, 2, 3};
    print_vector(vec.begin(), vec.cend());
    cout << endl;

    // Returning a Pointer to an Array
    typedef int arrT[10];  // arrT is a synonym for the type array of ten ints
    using arrtT = int[10]; // equivalent declaration of arrT;
    arrT *func(int);       // func returns a pointer to an array of ten ints

    //    Declaring a Function That Returns a Pointer to an Array
    int *func1(int);
    // int *[10] func2(int); // 这样没法定义
    // int(*)[10] func2(int); // 这样定义也是错的
    int(*func2(int))[10];

    // Using a Trailing Return Type
    // func3 takes an int argument and returns a pointer to an array of ten ints
    auto func3(int) -> int(*)[10];

    // Using decltype
    int arr[10] = {};
    decltype(arr) *func4(int); // returns a pointer to an array of ten int elements

    // exercise
    //  Write the declaration for a function that returns a reference to an array of ten strings, without using either a trailing return, decltype, or a type alias.
    string(&func5(void))[10];

    // Write three additional declarations for the function in the previous exercise. One should use a type alias, one should use a trailing return, and the third should use decltype.
    using arrST = string[10];
    arrST &func6(void);
    auto func7(void) -> string(&)[10];
    // string str(10, 0);
    string str[10] = {};

    decltype(str) &func8(void);

    // 这个临时类用于在main函数内部定义函数
    class temp
    {
        string (&func5(void))[10]
        {
            string ret[10] = {}; // 这里只是用于测试函数返回类型的正确性，所以不考虑返回的是不是局部变量
            return ret;
        }
        arrST &func6(void)
        {
            string ret[10] = {};
            return ret;
        }
        decltype(str) &func8(void)
        {
            string ret[10] = {};
            return ret;
        }
    };
}
