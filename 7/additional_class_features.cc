#include <string>
using std::string;

class Screen
{
public:
    // In addition to defining data and function members, a class can define its own local names for types. Type names defined by a class are subject to the same access controls as any other member and may be either public or private
    // We defined pos in the public part of Screen because we want users to use that name.
    typedef std::string::size_type pos;

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};