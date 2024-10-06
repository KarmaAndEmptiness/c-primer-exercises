#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using Iterator = string::iterator;
int main()
{
    // Unlike pointers, we do not use the address-of operator to obtain an iterator. Instead, types that have iterators have members that return iterators.
    string s("some string");
    auto begin = &(s[0]);
    auto end = &(s[s.size()]);
    cout << (*begin) << endl
         << (*(end - 1)) << endl
         << (*(s.begin())) << endl
         << (*(s.end() - 1)) << endl
         << "begin == s.begin(): " << ((Iterator)begin == s.begin()) << endl
         << "end == s.end(): " << ((Iterator)end == s.end()) << endl
         << "begin == s.end(): " << ((Iterator)begin == s.end()) << endl;

    if (s.begin() != s.end())
    {                        // make sure s is not empty
        auto it = s.begin(); // it denotes the first character in s
        *it = toupper(*it);  // make that character uppercase
    }
    cout << s << endl;

    for (auto it = s.begin(); it != s.end() && !isspace(*it); *it = toupper(*it), it++)
        ;
    cout << s << endl;

    // Just as we do not know the precise type of a vector’s or string’s size_type member, so too, we generally do not know—and do not need to know—the precise type of an iterator. Instead, as with size_type, the library types that have iterators define types named iterator and const_iterator that represent actual iterator type
    // if a vector or string is const, we may use only its const_iterator type.
    vector<int>::iterator it;        // it can read and write vector<int> elements
    string::iterator it2;            // it2 can read and write characters in a string
    vector<int>::const_iterator it3; // it3 can read but not write elements
    string::const_iterator it4;      // it4 can read but not write characters

    vector<int> v;
    const vector<int> cv;
    auto it1 = v.begin();  // it1 has type vector<int>::iterator
    auto it5 = cv.begin(); // it5 has type vector<int>::const_iterator
    auto it6 = v.cbegin(); // it6 has type vector<int>::const_iterator

    // exercise
    vector<int> temp{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto it = temp.begin(); it != temp.end(); it++)
        *it *= *it; // square the element value
    for (auto it = temp.cbegin(); it != temp.cend(); it++)
        cout << (*it) << " ";
    cout << endl;

    // compute an iterator to the element closest to the midpoint of vi
    auto mid = temp.begin() + temp.size() / 2;
    cout << (*mid) << endl;

    for (auto it = temp.cbegin(); it < temp.cend(); it++)
        if (it < mid) // process elements in the first half of vi
            cout << (*it) << " ";
    cout << endl;

    string::difference_type diffrence = temp.cbegin() + 5 - temp.cbegin();

    {
        auto begin = temp.cbegin(), end = temp.cend();
        auto mid = begin + (end - begin) / 2;
        int target = 16;
        // target = 3;

        while (*mid != target && mid != end)
        {
            if (target < *mid)
                end = mid;
            else
                begin = mid + 1;
            mid = begin + (end - begin) / 2; // 计算出离begin最近的中位数。 It operates by looking at the element closest to the middle of the sequence.
            cout << (*mid) << " ";
        }
        cout << endl;
        if (*mid == target)
            cout << "get it!" << endl;
    }

    return 0;
}