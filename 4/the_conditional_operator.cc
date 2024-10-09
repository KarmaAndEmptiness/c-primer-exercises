#include <iostream>
using std::cout;
using std::endl;
int main()
{
    int grade = 10;
    cout << ((grade < 60) ? "fail" : "pass") << endl; // prints pass or  fail
    cout << (grade < 60) ? "fail" : "pass";           // 从左到右计算。 prints 1 or 0!
    cout << endl;
    // cout << grade < 60 ? "fail" : "pass"; //  error: compares cout to 60
    cout << endl;
    return 0;
}