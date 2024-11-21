#include <iostream>
#include <fstream>
#include <string>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::ends;
using std::flush;
using std::iostream;
using std::istream;
using std::nounitbuf;
using std::ofstream;
using std::ostream;
using std::string;
using std::unitbuf;
// exercises
//  Write a function that takes and returns an istream&. The function should read the stream until it hits end-of-file. The function should print what it reads to the standard output. Reset the stream so that it is valid before returning the stream.
istream &read_until_eof(istream &input)
{
    string line;
    // 逐行读取直到遇到 EOF
    while (getline(input, line))
    {
        cout << line << endl; // 打印读取到的内容
    }

    // 重置流的状态，清除任何错误标志
    input.clear(); // 重置错误标志
    return input;  // 返回流
}
int main()
{

    // No Copy or Assign for IO Objects
    ofstream out1, out2;
    // out1 = out2;              // error: cannot assign stream objects
    ofstream print(ofstream); // print函数的声明 error: can't initialize the ofstream parameter
    // out2 = print(out2);       // error: cannot copy stream objects

    // Condition States
    // The IO classes define functions and flags
    // ofstream::iostate;
    iostream::badbit;

    // Test your function by calling it, passing cin as an argument.
    // read_until_eof(cin);

    // Flushing the Output Buffer
    // There are two other similar manipulators: flush and ends. flush flushes the stream but adds no characters to the output; ends inserts a null character into the buffer and then flushes it
    cout << "hi!" << endl;  // writes hi and a newline, then flushes the buffer
    cout << "hi!" << flush; // writes hi, then flushes the buffer; adds no data
    cout << "hi!" << ends;  // writes hi and a null, then flushes the buffer
    cout << endl;

    // The unitbuf Manipulator
    // If we want to flush after every output, we can use the unitbuf manipulator. This manipulator tells the stream to do a flush after every subsequent write. The nounitbuf manipulator restores the stream to use normal, system-managed buffer flushing
    cout << unitbuf; // all writes will be flushed immediately
    // any output is flushed immediately, no buffering
    cout << nounitbuf; // returns to normal buffering

    cin.tie(nullptr); // 解除cin与cout的绑定
    cin.tie(&cerr);   // 将cin绑定cerr
    // Each stream can be tied to at most one stream at a time
    cin.tie(&cout); // 将cin绑定cout;
    // multiple streams can tie themselves to the same ostream
    cerr.tie(&cout); // 将 cerr 也绑定到 cout
    cout << (cin.tie() == &cout) << endl;

    cin.tie(&cout); // illustration only: the library ties cin and cout for us
    // old_tie points to the stream (if any) currently tied to cin
    ostream *old_tie = cin.tie(nullptr); // 这里调用的是带参的tie函数，返回值是&cout cin is no longer tied
    // ties cin and cerr; not a good idea because cin should be tied to cout
    cin.tie(&cerr);   // reading cin flushes cerr, not cout
    cin.tie(old_tie); // reestablish normal tie between cin and cout
    cout << (cin.tie() == &cout) << endl;
    return 0;
}