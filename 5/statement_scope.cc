#include <iostream>
using std::cout;
using std::endl;
int get_num()
{
    return 1;
}
int main()
{
    while (int i = get_num()) // i is created and initialized on each iteration
        cout << i << endl;
    return 0;
}