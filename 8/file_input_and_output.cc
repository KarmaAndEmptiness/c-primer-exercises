#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::endl;
using std::ifstream;
using std::istream;
using std::ofstream;
using std::ostream;
using std::string;

void read(istream &is, string &buffer)
{
    is >> buffer;
}

void print(ostream &os, string &buffer)
{
    os << buffer;
}

int main(const int argc, const char *argv[])
{
    cout << argc << "  ";
    for (size_t i = 0; i < argc; i++)
    {
        cout << argv[i] << "  ";
    }
    cout << endl;

    ifstream input(argv[1]);
    ofstream output(argv[2], ofstream::app);

    //  We can pass our fstream objects to these functions even though the parameters to those functions are defined as istream& and ostream&, respectively.
    string buffer;
    read(input, buffer);
    print(output, buffer);

    return 0;
}