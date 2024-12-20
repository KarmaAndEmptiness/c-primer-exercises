#include <string>
using std::string;
class HasPtr
{
public:
    // note rhs is passed by value, which means the HasPtr copy constructor
    // copies the string in the right-hand operand into rhs
    HasPtr &HasPtr::operator=(HasPtr rhs);

    friend void swap(HasPtr &, HasPtr &);

private:
    std::string *ps;
    int i;
};
// As we’ve already seen, the library swap makes unnecessary copies of the strings managed by HasPtr.
inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps); // swap the pointers, not the string data
    swap(lhs.i, rhs.i);   // swap the int members
}

class Foo
{
    friend void swap(Foo &, Foo &);

private:
    HasPtr h;
};
inline void swap(Foo &lhs, Foo &rhs)
{
    // WRONG: this function uses the library version of swap, not the HasPtr version
    // std::swap(lhs.h, rhs.h);//这里是直接调用的std::swap
    // swap other members of type Foo

    using std::swap;
    // 这里调用的是HasPtrValueLike中的swap函数
    swap(lhs.h, rhs.h); // uses the HasPtr version of swap
    // swap other members of type Foo
}
// note rhs is passed by value, which means the HasPtr copy constructor
// copies the string in the right-hand operand into rhs
HasPtr &HasPtr::operator=(HasPtr rhs)
{
    // swap the contents of the left-hand operand with the local variable rhs
    swap(*this, rhs); // rhs now points to the memory this object had used
    return *this;     // rhs is destroyed, which deletes the pointer in rhs
}
int main()
{

    return 0;
}