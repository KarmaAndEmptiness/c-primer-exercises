#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
int main()
{
    {
        string s("some string");
        auto beg = s.begin();

        // the behavior of the following loop is undefined!
        while (beg != s.end() && !isspace(*beg))
            *beg = toupper(*beg++); // error: this assignment is undefined
        cout << s << endl;
    }

    {
        string s("some string");
        auto beg = s.begin();
        while (beg != s.end() && !isspace(*beg))
        {
            *(beg++) = toupper(*beg);
        }
        cout << s << endl;
    }

    return 0;
}