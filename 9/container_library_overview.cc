#include <iostream>
#include <string>
#include <list>
#include <vector>
using std::cout;
using std::endl;
using std::list;
using std::string;
using std::vector;
int main()
{
    //  The assign operation replaces all the elements in the left-hand container with (copies of) the elements specified by its arguments. For example, we can use assign to assign a range of char* values from a vector into a list of string
    list<string> names;
    vector<const char *> oldstyle;

    // names = oldstyle; // error: container types don't match

    // ok: can convert from const char*to string
    names.assign(oldstyle.cbegin(), oldstyle.cend());

    // The swap operation exchanges the contents of two containers of the same type. After the call to swap, the elements in the two containers are interchanged
    vector<string> svec1(10); // vector with ten elements
    vector<string> svec2(24); // vector with 24 elements
    swap(svec1, svec2);

    const vector<int> v2({1, 2, 3});
    // v2.push_back(4);      // 编译错误：push_back 不能用于常量容器
    // v2.erase(v2.begin()); // 编译错误：erase 不能用于常量容器

    // 这里调用的是构造函数,不是operator
    vector<string> t{"hello"};
    string t1{"world"};
    string t2(t1.begin(), t1.end());
    cout << t2 << endl;
    return 0;
}