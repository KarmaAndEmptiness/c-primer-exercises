#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main()
{
    // 以下代码会出现死循环 Variables defined in a while condition or while body are created and destroyed on each iteration.
    // while (int i = 10)
    // {
    //     cout << i-- << " ";
    // }
    // cout << endl;

    // exercise
    string word;
    string target;
    int cnt = 0;
    if (cin >> word)
    {
        target = word;
        cnt++;
        while (cin >> word)
        {

            if (!target.empty() && word == target)
            {
                cnt++;
                continue;
            }
            if (target != word)
            {
                cout << target << " appears " << cnt << " times." << endl;
                target = word;
                cnt = 1;
            }
        }
        cout << target << " appears " << cnt << " times." << endl;
    }

    // A for header can omit any (or all) of init-statement, condition, or expression.

    // We can use a null statement for init-statement when an initialization is unnecessary.
    vector<int> v = {1, 3, 2, -1};
    auto beg = v.begin();
    for (/* null */; beg != v.end() && *beg >= 0; ++beg) // Note that the semicolon is necessary to indicate the absence of init-statement—more precisely, the semicolon represents a null init-statement.
        ;                                                // no work to do

    // Omitting condition is equivalent to writing true as the condition.
    // Because the condition always evaluates as true, the for body must contain a statement that exits the loop
    for (int i = 0; /* no condition */; ++i) // 死循环
    {
        // process i; code inside the loop must stop the iteration!
        break;
    }

    // We can also omit expression from the for header.
    for (int i; cin >> i; /* no expression */)
        v.push_back(i);

    for (;;) // 死循环
        break;

    // Range for Statement
    //  expression must represent a sequence, such as a braced initializer list, an array, or an object of a type such as vector or string that has begin and end members that return iterators.
    for (auto &&i : {2, 3, 4, 5}) // a braced initializer list
    {
        break;
    }

    // Given two vectors of ints, write a program to determine whether one vector is a prefix of the other. For vectors of unequal length, compare the number of elements of the smaller vector. For example, given the vectors containing 0, 1, 1, and 2 and 0, 1, 1, 2, 3, 5, 8, respectively your program should return true.
    vector<int> v1 = {0, 1, 1, 2};
    vector<int> v2 = {0, 1, 1, 2, 3, 5, 8};
    vector<int> v3{2, 3, 4};
    bool is_prefix(const vector<int> &v1, const vector<int> &v2);
    cout << is_prefix(v1, v2) << "  "
         << is_prefix(v1, v3) << "  "
         << endl;

    // Because the condition is not evaluated until after the statement or block is executed, the do while loop does not allow variable definitions inside the condition
    // do
    // {
    //     // . . .
    //     mumble(foo);
    // } while (int foo = get_foo()); // error: declaration in a do condition

    return 0;
}
bool is_prefix(const vector<int> &v1, const vector<int> &v2)
{
    int min_len = std::min(v1.size(), v2.size());
    for (size_t i = 0; i < min_len; i++)
    {
        if (v1[i] != v2[i])
            return false;
    }
    return true;
}