#include <string>
using std::string;
class HasPtr
{
    friend void swap(HasPtr &, HasPtr &);

private:
    std::string *ps;
    int i;
};
inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps); // swap the pointers, not the string data
    swap(lhs.i, rhs.i);   // swap the int members
}

int main()
{

    return 0;
}