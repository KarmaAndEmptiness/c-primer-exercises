#include <numeric>
#include <vector>
#include <string>
#include <list>
#include <algorithm> //replace、replace_copy函数
using std::accumulate;
using std::begin;
using std::copy;
using std::end;
using std::list;
using std::string;
using std::vector;

// Once the vector is sorted, we can use another library algorithm, named unique, to reorder the vector so that the unique elements appear in the first part of the vector.
void elimDups(vector<string> &words)
{
    // sort words alphabetically so we can find the duplicates
    sort(words.begin(), words.end());
    // unique  reorders the input range so that each word appears once in the
    // front portion of the range and returns an iterator one past the unique range
    auto end_unique = unique(words.begin(), words.end());
    // erase uses a vector operation to remove the nonunique elements
    words.erase(end_unique, words.end());
}
int main()
{
    {

        vector<int> vec = {1, 2, 3};
        // Read-Only Algorithms
        // sum the elements in vec starting the summation with the value 0
        int sum = accumulate(vec.cbegin(), vec.cend(), 0);
    }
    {
        vector<string> vec = {"hello"};
        // The fact that accumulate uses its third argument as the starting point for the summation has an important implication: It must be possible to add the element type to the type of the sum. That is, the elements in the sequence must match or be convertible to the type of the third argument.
        string sum = accumulate(vec.cbegin(), vec.cend(), string(""));

        // error: no + on const char*
        // sum = accumulate(vec.cbegin(), vec.cend(), "");
    }
    {

        vector<int> vec;              // empty vector
        auto it = back_inserter(vec); // assigning through it adds elements to vec
        *it = 42;                     // vec now has one element with value 42

        // ok: back_inserter creates an insert iterator that adds elements to vec
        fill_n(back_inserter(vec), 10, 0); // appends ten elements to vec
    }

    {
        int a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        int a2[sizeof(a1) / sizeof(*a1)]; // a2 has the same size as a1
        // ret points just past the last element copied into a2
        auto ret = copy(begin(a1), end(a1), a2); // copy a1 into a2
    }
    {
        vector<int> ivec;
        list<int> ilst = {1, 2, 3};

        // 直接修改容器里的值
        //  replace any element with the value 0 with 42
        replace(ilst.begin(), ilst.end(), 0, 42);

        // 将结果输出到ivec容器里面
        //  use back_inserter to grow destination as needed
        replace_copy(ilst.cbegin(), ilst.cend(),
                     back_inserter(ivec), 0, 42);
    }
    return 0;
}