#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
int main()
{
    int i = 0;
    cout << i << " " << ++i << endl; // undefined
    vector<int> vec = {1, 3, 4};
    cout << *vec.begin() << endl;
    cout << *vec.begin() + 1 << endl;
    return 0;
}