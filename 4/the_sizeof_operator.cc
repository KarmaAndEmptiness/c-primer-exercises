#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;
void fv()
{
}
int fi()
{
    return 0;
}
int main()
{
    const char s[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    cout << sizeof s << endl; // 6

    const int ia[] = {1, 2, 3};
    cout << sizeof ia << endl; // 12 It is equivalent to taking the sizeof the element type times the number of elements in the array. Note that sizeof does not convert the array to a pointer.

    // sizeof a string or a vector returns only the size of the fixed part of these types; it does not return the size used by the object’s elements.
    // string 和 vector 是 C++ 标准库中的动态数据结构。它们都有一个固定部分和一个可变部分。
    string s1 = "hello";
    cout << "sizeof s1: " << sizeof s1 << endl // 32
         << "sizeof(s1): " << sizeof(s1) << endl;

    vector<int> ivec = {1, 2, 3};
    cout << "sizeof ivec: " << sizeof ivec << "  sizeof ivec/sizeof(int): " << sizeof ivec / sizeof(int) << endl // 24 6
         << "sizeof(ivec): " << sizeof(ivec) << endl;

    // exercise
    int x[10];
    int *p = x;
    int(*pa)[10] = &x;
    cout << "sizeof(x): " << sizeof(x) << endl
         << "sizeof(*x): " << sizeof(*x) << endl;
    cout << "sizeof(p): " << sizeof(p) << endl
         << "sizeof(*p): " << sizeof(*p) << endl;
    cout << "sizeof(x)/sizeof(*x): " << sizeof(x) / sizeof(*x) << endl
         << "(sizeof(x)/sizeof(*x)): " << (sizeof(x) / sizeof(*x)) << endl
         << "sizeof(p)/sizeof(*p): " << sizeof(p) / sizeof(*p) << endl
         << "(sizeof(p)/sizeof(*p)): " << (sizeof(p) / sizeof(*p)) << endl
         << "sizeof(pa)/sizeof(*pa): " << sizeof(pa) / sizeof(*pa) << endl
         << "(sizeof(pa)/sizeof(*pa)): " << (sizeof(pa) / sizeof(*pa)) << endl;

    {
        struct MyStruct
        {
            int mem[10] = {0, 3, 9};
        };

        MyStruct *p = new MyStruct();
        int i = 2;

        // sizeof p->mem[i] 等价于:
        sizeof((p->mem)[i]); // 结果是 sizeof(int)
        cout << "sizeof p->mem[i]: " << sizeof p->mem[i] << "  "
             << "sizeof((p->mem)[i]): " << sizeof((p->mem)[i]) << "  "
             << "sizeof(p->mem[i]): " << sizeof(p->mem[i]) << endl;

        int a = 2, b = 3;
        // constexpr size_t temp=sizeof a<b;//error
        constexpr size_t temp = sizeof(a < b);
        // cout << "sizeof a<b: " << temp << endl;
        cout << "sizeof(a<b): " << temp << endl;

        cout << sizeof fv() << endl
        <<sizeof fi()<<endl;
    }

    return 0;
}