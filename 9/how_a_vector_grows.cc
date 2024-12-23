#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    string s;

    // Small String Optimization
    cout << "after string s" << endl
         << "s.capacity(): " << s.capacity() << endl;

    // A call to reserve changes the capacity of the vector only if the requested space exceeds the current capacity.
    s.reserve(20);
    cout << "after s.reserve(20)" << endl
         << "s.capacity(): " << s.capacity() << endl;

    s = "hello";
    cout << "after s=\"hello\";" << endl
         << "s.capacity(): " << s.capacity() << "  "
         << "s.size(): " << s.size() << endl;

    s.shrink_to_fit();
    cout << "after s.shrink_to_fit()" << endl
         << "s.size(): " << s.size() << endl //
         << "s.capacity(): " << s.capacity() << endl;

    s.resize(6, 'a');
    cout << "after s.resize(6,\'a\')" << endl
         << "s.size(): " << s.size() << endl
         << "s.capacity(): " << s.capacity() << endl
         << "s: " << s << endl;

    vector<int> vi;
    cout << "after vector<int> vi: " << endl
         << "vi.capacity(): " << vi.capacity() << endl; // 0

    vi = {1, 2, 3};
    cout << "after vi={1,2,3}" << endl
         << "vi.capacity(): " << vi.capacity() << endl; // 3

    vi.resize(2, 3);
    cout << "after vi.resize(2,3)" << endl
         << "vi.capacity(): " << vi.capacity() << endl // 3
         << "vi.size(): " << vi.size() << endl;        // 2

    vi.shrink_to_fit();
    cout << "after vi.shrink_to_fit()" << endl
         << "vi.capacity(): " << vi.capacity() << endl
         << "vi.size(): " << vi.size() << endl;

    return 0;
}