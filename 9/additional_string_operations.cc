#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::to_string;

// exercise
void replaceString(std::string &s, const std::string &oldVal, const std::string &newVal)
{
    auto it = s.begin();
    while (it <= s.end() - oldVal.size())
    { // 确保剩余长度足够匹配 oldVal
        if (std::string(it, it + oldVal.size()) == oldVal)
        {                                                    // 检查子串是否匹配
            it = s.erase(it, it + oldVal.size());            // 删除 oldVal
            it = s.insert(it, newVal.begin(), newVal.end()); // 插入 newVal
            it += newVal.size();                             // 调整迭代器位置
        }
        else
        {
            ++it; // 向前移动迭代器
        }
    }
}
int main()
{
    {
        // The constructors that take a string or a const char* take additional (optional) arguments that let us specify how many characters to copy. When we pass a string, we can also specify the index of where to start the copy
        const char *cp = "Hello World!!!"; // null-terminated array
        char noNull[] = {'H', 'i'};        // not null terminated
        string s1(cp);                     // copy up to the null in cp; s1 == "Hello World!!!"
        string s2(noNull, 2);              // copy two characters from no_null; s2 == "Hi"
        string s3(noNull);                 // undefined: noNull not null terminated
        string s4(cp + 6, 5);              // copy 5 characters starting at cp[6]; s4 == "World"
        string s5(s1, 6, 5);               // copy 5 characters starting at s1[6]; s5 == "World"
        string s6(s1, 6);                  // copy from s1 [6] to end of s1; s6 == "World!!!"
        string s7(s1, 6, 20);              // ok, copies only to end of s1; s7 == "World!!!"
        // string s8(s1, 16);                 // throws an out_of_range exception
    }
    {
        string s = "some string", s2 = "some other string";
        s.insert(0, s2); // insert a copy of s2 before position 0 in s

        cout << "after s.insert(0,s2)" << endl
             << "s: " << s << endl;

        // insert s2.size() characters from s2 starting at s2[0] before s[0]
        s.insert(0, s2, 0, s2.size());
        cout << "after s.insert(0, s2, 0, s2.size())" << endl
             << "s: " << s << endl;
    }
    {
        // The append and replace Functions
        // The string class defines two additional members, append and replace, that can change the contents of a string. summarizes these functions. The append operation is a shorthand way of inserting at the end:
        string s("C++ Primer"), s2 = s; // initialize s and s2 to "C++ Primer"
        s.insert(s.size(), " 4th Ed."); // s == "C++ Primer 4th Ed."
        s2.append(" 4th Ed.");          // equivalent: appends " 4th Ed." to s2; s == s2

        // equivalent way to replace "4th" by "5th"
        s.erase(11, 3);      // s == "C++ Primer Ed."
        s.insert(11, "5th"); // s == "C++ Primer 5th Ed."
        // starting at position 11, erase three characters and then insert "5th"
        s2.replace(11, 3, "5th"); // equivalent: s == s2

        cout << "after s2.replace(11,3,\"5th\");" << endl
             << s2 << endl;
    }

    // exercise
    {
        // Write a function that takes three strings, s, oldVal, and newVal. Using iterators, and the insert and erase functions replace all instances of oldVal that appear in s by newVal. Test your function by using it to replace common abbreviations, such as “tho” by “though” and “thru” by “through”.
        std::string text = "I went thru the park tho it was raining.";
        std::cout << "Original text: " << text << std::endl;

        replaceString(text, "tho", "though");
        replaceString(text, "thru", "through");

        std::cout << "Modified text: " << text << std::endl;
    }

    {
        // The find function does the simplest search. It looks for its argument and returns the index of the first match that is found, or npos if there is no match
        string name("AnnaBelle");
        auto pos1 = name.find("Anna"); // pos1 == 0
        cout << "pos1: " << pos1 << endl;

        string lowercase("annabelle");
        pos1 = lowercase.find("Anna"); // pos1 == npos
        cout << "pos1: " << pos1 << endl;
    }

    {
        // A slightly more complicated problem requires finding a match to any character in the search string. For example, the following locates the first digit within name
        string numbers("0123456789"), name("r2d2");
        // returns 1, i.e., the index of the first digit in name
        auto pos = name.find_first_of(numbers);
        cout << "pos: " << pos << endl;

        string dept("03714p3");
        // returns 5, which is the index to the character 'p'
        pos = dept.find_first_not_of(numbers);
        cout << "pos: " << pos << endl;

        // We can pass an optional starting position to the find operations. This optional argument indicates the position from which to start the search. By default, that position is set to zero. One common programming pattern uses this optional argument to loop through a string finding all occurrences
        string::size_type pos = 0;
        // each iteration finds the next number in name
        while ((pos = name.find_first_of(numbers, pos)) != string::npos)
        {
            cout << "found number at index: " << pos
                 << " element is " << name[pos] << endl;
            ++pos; // move to the next character
        }

        // Searching Backward
        string river("Mississippi");
        auto first_pos = river.find("is"); // returns 1
        auto last_pos = river.rfind("is"); // returns 4
    }

    {
        int i = 42;
        string s = to_string(i); // converts the int i to its character representation
        double d = stod(s);      // converts the string s to floating-point

        // The first non-whitespace character in the string we convert to numeric value must be a character that can appear in a number
        string s2 = "pi = 3.14";
        // convert the first substring in s that starts with a digit,  d = 3.14
        d = stod(s2.substr(s2.find_first_of("+-.0123456789")));
    }

    return 0;
}