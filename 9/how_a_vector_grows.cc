#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

int main()
{
    string s;
    // A call to reserve changes the capacity of the vector only if the requested space exceeds the current capacity.
    s.reserve(20);
    s = "hello";
    s.shrink_to_fit();
    cout << s.size() << endl;
    cout << s.capacity() << endl;
    s.resize(6, 'a');
    cout << s.size() << endl;
    cout << s.capacity() << endl;
    cout << s << endl;
    return 0;
}