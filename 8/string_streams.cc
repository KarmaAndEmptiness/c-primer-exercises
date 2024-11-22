#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::istringstream;
using std::ostream;
using std::ostringstream;
using std::string;
using std::vector;
struct PersonInfo
{
    string name;
    vector<string> phones;
};
bool valid(string nums)
{
    return true;
}
string format(string nums)
{
    return nums;
}

void print(ostream &os, vector<PersonInfo> &people)
{
    for (const auto &entry : people)
    {                                     // for each entry in people
        ostringstream formatted, badNums; // objects created on each loop
        for (const auto &nums : entry.phones)
        { // for each number
            if (!valid(nums))
            {
                badNums << " " << nums; // string in badNums
            }
            else
                // ''writes'' to formatted's string
                formatted << " " << format(nums);
        }
        if (badNums.str().empty())         // there were no bad numbers
            os << entry.name << " "        // print the name
               << formatted.str() << endl; // and reformatted numbers
        else                               // otherwise, print the name and bad numbers
            cerr << "input error: " << entry.name
                 << " invalid number(s) " << badNums.str() << endl;
    }
}
int main()
{
    string line, word;         // will hold a line and word from input, respectively
    vector<PersonInfo> people; // will hold all the records from the input
    // read the input a line at a time until cin hits end-of-file (or another error)
    while (getline(cin, line)) // cin是一个istream类型的全局对象 从标准输入中读入数据
    {
        PersonInfo info; // create an object to hold this record's data
        // The difference is that this loop reads data from a string rather than from the standard input.
        istringstream record(line);      // bind record to the line we just read 从line这个string对象中读入数据
        record >> info.name;             // read the name
        while (record >> word)           // read the phone numbers
            info.phones.push_back(word); // and store them
        people.push_back(info);          // append this record to people
    }

    // for (auto &&i : people)
    // {
    //     cout << i.name << " ";
    //     for (auto &&j : i.phones)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    print(cout, people);
    return 0;
}