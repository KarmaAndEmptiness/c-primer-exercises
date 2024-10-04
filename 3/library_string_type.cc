#include <iostream>
#include <string>
#include <cctype> //Ordinarily, C++ programs should use the cname versions of headers and not the name.h versions.
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{

    // When we mix strings and string or character literals, at least one operand to each + operator must be of string type.
    string s1 = "hello, ", s2 = "world\n";
    string s4 = s1 + ", "; // ok: adding a string and a literal
    // string s5 = "hello" + ", ";      // error: no string operand
    string s6 = s1 + ", " + "world"; // 等价于string s6 = (s1 + ", ") + "world"; ok: each + has a string operand
    // string s7 = "hello" + ", " + s2; //从左往右 error: can't add string literals
    // string s7 = ("hello" + ", ") + s2; // error: can't add string literals
    string s8 = (string) "hello " + "world"; // For historical reasons, and for compatibility with C, string literals are not standard library strings. It is important to remember that these types differ when you use string literals and library strings.
    cout << s8 << endl;

    // These operators use the same strategy as a (case-sensitive) dictionary:
    // If two strings have different lengths and if every character in the shorter string is equal to the corresponding character of the longer string, then the shorter string is less than the longer one.
    // If any characters at corresponding positions in the two strings differ, then the result of the string comparison is the result of comparing the first character at which the strings differ.
    string str = "Hello";
    string phrase = "Hello World";
    string slang = "Hiya";
    string test1 = "Ha", test2 = "Hz";
    cout << "str > phrase: " << (str > phrase) << endl;
    cout << "str > slang: " << (str > slang) << endl;
    cout << "phrase > slang: " << (phrase > slang) << endl; //"Hiya"中的"i"比"Hello"中的"e"在字母表中位置靠后
    cout << "slang > test1: " << (slang > test1) << endl;
    cout << "slang > test2: " << (slang > test2) << endl;

    cout << isdigit('12') << endl;

    string s("Hello World!!!");
    // punct_cnt has the same type that s.size returns; see § 2.5.3 (p. 70)
    decltype(s.size()) punct_cnt = 0;
    // count the number of punctuation characters in s
    for (auto c : s)     // for every char in s
        if (ispunct(c))  // if the character is punctuation
            ++punct_cnt; // increment the punctuation counter
    cout << punct_cnt
         << " punctuation characters in " << s << endl;

    string s3("some string");
    if (!s3.empty())            // make sure there's a character in s3[0]
        s3[0] = toupper(s3[0]); // assign a new value to the first character in s3
    cout << "s3: " << s3 << endl;

    // process characters in s until we run out of characters or we hit a whitespace
    for (decltype(s3.size()) index = 0;
         index != s3.size() && !isspace(s3[index]); ++index)
        s3[index] = toupper(s3[index]); // capitalize the current character
    cout << "s3: " << s3 << endl;

    // The string input operator reads and discards any leading whitespace (e.g., spaces, newlines, tabs). It then reads characters until the next whitespace character is encountered.
    // 读入直到遇到一个whitespace,打印接着读入下一个
    string word;
    while (cin >> word) // read until end-of-file
    {
        cout << word << endl;
    }

    string line;
    // read input a line at a time until end-of-file
    // The newline that causes getline to return is discarded; the newline is not stored in the string.
    while (getline(cin, line))
    {
        // read input a line at a time and discard blank lines
        if (!line.empty())
            cout << line << endl;
    }

    // Although we don’t know the precise type of string::size_type, we do know that it is an unsigned type big enough to hold the size of any string.
    // string::size_type ss=line.size();
    auto ss = line.size();
    return 0;
}