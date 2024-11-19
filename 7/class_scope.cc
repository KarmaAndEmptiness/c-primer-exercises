#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::string;

int height = 1; // defines a name subsequently used inside Screen
class Screen
{
public:
    typedef std::string::size_type pos;
    Screen() = default; // needed because Screen has another constructor
    // cursor initialized to 0 by its in-class initializer
    Screen(pos ht, pos wd, char c) : height(ht), width(wd),
                                     contents(ht * wd, c) {}
    Screen(pos ht, pos wd) : height(ht), width(wd),
                             contents("") {}

    void dummy_fcn(pos height)
    {
        cursor = width * height; // which height? the parameter
        pos para = height;
        pos member = this->height; // member
        int outside = ::height;    // outside
        cout << "para: " << para << "  member: " << member << "  outside: " << outside << endl;
    }
    //  error: 'verify' was not declared in this scope
    // 在检查setHeight定义时的外部作用域(这里是Screen里面)时，没有找到verify
    // void setHeight(pos var) { height = verify(var); }
    void setHeight(pos);

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

Screen::pos verify(Screen::pos);
Screen::pos verify(Screen::pos) { return 0; }
void Screen::setHeight(pos var)
{
    // var: refers to the parameter
    // height: refers to the class member
    // verify: refers to the global function

    // 全局函数 verify 的声明在 setHeight 定义之前，但在类 Screen 定义之后。
    //  根据名字查找的规则，编译器在查找 verify 时会：
    //  先检查 setHeight 函数内部是否有这个名字；
    //  然后检查类 Screen 的作用域；
    //  最后检查 setHeight 定义时的外部作用域（这里找到了全局函数 verify）。
    height = verify(var);
}
class Window_mgr
{
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    // add a Screen to the window and returns its index
    ScreenIndex addScreen(const Screen &);
    // other members as before
private:
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};

// the return type of a function normally appears before the function’s name. When a member function is defined outside the class body, any name used in the return type is outside the class scope. As a result, the return type must specify the class of which it is a member.
// 返回类型要类名 Because the return type appears before the name of the class is seen, it appears outside the scope of class Window_mgr. To use ScreenIndex for the return type, we must specify the class in which that type is defined.
// return type is seen before we're in the scope of Window_mgr
Window_mgr::ScreenIndex
Window_mgr::addScreen(const Screen &s)
{
    screens.push_back(s);
    return screens.size() - 1;
}

// 这个名字在成员函数中使用而类中有，因此成员函数会使用类中的，而不会使用这里的
string bal;

// 这个类型定义是为了定义类中的member，所以它必须定义在类的所有member之前
typedef double Money;
class Account
{

public:
    // 可以在这里重新定义Money类型
    typedef double Money;
    //  If a member declaration uses a name that has not yet been seen inside the class, the compiler will look for that name in the scope(s) in which the class is defined.
    // 如果在class 内部找不到名字就在这个class定义的scope里面找
    // the function body of balance is processed only after the entire class is seen. Thus, the return inside that function returns the member named bal, not the string from the outer scope.
    // bal用的是class内部的
    Money balance() { return bal; }

private:
    // The compiler considers only declarations inside Account that appear before the use of Money.
    // 这个类型定义在balance这个函数后面它访问不到
    //  typedef double Money;

    // Ordinarily, an inner scope can redefine a name from an outer scope even if that name has already been used in the inner scope. However, in a class, if a member uses a name from an outer scope and that name is a type, then the class may not subsequently redefine that name
    // typedef double Money; // error: cannot redefine Money 不能在这里重新定义类型，因为前面的balance函数用的是class 外面定义的Money类型
    Money bal;
    // ...
};

// exercises
typedef string Type;
Type initVal();
class Exercise
{
public:
    typedef double Type;
    Type setVal(Type);
    // Type initVal();
    Type initVal() { return 0; }

private:
    int val;
};
Exercise::Type Exercise::setVal(Type parm)
{
    val = parm + initVal();
    return val;
}

int main()
{
    Screen s;
    s.dummy_fcn(2);
    return 0;
}
