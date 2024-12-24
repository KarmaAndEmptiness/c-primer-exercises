#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using std::cout;
using std::endl;
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
    return 0;
}