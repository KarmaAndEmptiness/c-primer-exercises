#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::vector;

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

bool isLongerThan(const std::string &str, size_t size)
{
    return str.size() > size;
}

void fcn2()
{
    size_t v1 = 42; // local variable
    // the object f2 contains a reference to v1
    auto f2 = [&v1]
    { return v1; };
    v1 = 0;
    auto j = f2(); // j is 0; f2 refers to v1; it doesn't store it
}

// Reference captures are sometimes necessary. For example, we might want our biggies function to take a reference to an ostream on which to write and a character to use as the separator
void biggies(vector<string> &words,
             vector<string>::size_type sz,
             ostream &os = cout, char c = ' ')
{
    // code to reorder words as before
    // statement to print count revised to print to os
    for_each(words.begin(), words.end(),
             [&os, c](const string &s)
             { os << s << c; });
}
int main()
{
    vector<string> words = {"world!", "hello", "abcdef"};
    sort(words.begin(), words.end(), isShorter);
    for (const auto &s : words) // no need to copy the strings
        cout << s << " ";       // print each element separated by a space
    cout << endl;

    sort(words.begin(), words.end(), [](const string &s1, const string &s2)
         { return true; });
    for (const auto &s : words) // no need to copy the strings
        cout << s << " ";       // print each element separated by a space
    cout << endl;

    // // resort by length, maintaining alphabetical order among words of the same length
    stable_sort(words.begin(), words.end(), isShorter);
    for (const auto &s : words) // no need to copy the strings
        cout << s << " ";       // print each element separated by a space
    cout << endl;

    // find_if takes a unary predicate—any function we pass to find_if must have exactly one parameter that can be called with an element from the input sequence. There is no way to pass a second argument representing the size. To solve this part of our problem we’ll need to use some additional language facilities.
    {
        std::vector<std::string> words = {"apple", "banana", "pear", "peach"};
        size_t size = 5;

        // 使用 Lambda 表达式
        auto it = std::find_if(words.begin(), words.end(),
                               [size](const std::string &s)
                               { return s.size() > size; });

        if (it != words.end())
        {
            std::cout << "First word longer than " << size << " is: " << *it << std::endl;
        }
        else
        {
            std::cout << "No word longer than " << size << std::endl;
        }
    }

    {
        std::vector<std::string> words = {"apple", "banana", "pear", "peach"};
        size_t size = 5;

        // 使用 std::bind 绑定 size 参数
        auto boundPredicate = std::bind(isLongerThan, std::placeholders::_1, size);
        auto it = std::find_if(words.begin(), words.end(), boundPredicate);

        if (it != words.end())
        {
            std::cout << "First word longer than " << size << " is: " << *it << std::endl;
        }
        else
        {
            std::cout << "No word longer than " << size << std::endl;
        }
    }
    {
        auto f = [](int a = 1)
        { return a; };
        f();
    }

    {
        int sz = 6;
        // get an iterator to the first element whose size() is >= sz
        auto wc = find_if(words.begin(), words.end(),
                          [sz](const string &a)
                          { return a.size() >= sz; });
        // print words of the given size or longer, each one followed by a space
        for_each(wc, words.end(),
                 [](const string &s)
                 { cout << s << " "; });
        cout << endl;
    }
    return 0;
}