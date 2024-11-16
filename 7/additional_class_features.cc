#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::string;
using std::vector;
class Window_mgr;
class Screen
{
public:
    // In addition to defining data and function members, a class can define its own local names for types. Type names defined by a class are subject to the same access controls as any other member and may be either public or private
    // We defined pos in the public part of Screen because we want users to use that name.
    typedef std::string::size_type pos;

    Screen() = default; // needed because Screen has another constructor
    // cursor initialized to 0 by its in-class initializer
    Screen(pos ht, pos wd, char c) : height(ht), width(wd),
                                     contents(ht * wd, c) {}
    Screen(pos ht, pos wd) : height(ht), width(wd),
                             contents("") {}
    char get() const // get the character at the cursor
    {
        return contents[cursor];
    } // implicitly inline
    inline char get(pos ht, pos wd) const; // explicitly inline
    Screen &move(pos r, pos c);            // can be made inline later

    void some_member() const;

    Screen &set(char);
    Screen &set(pos, pos, char);

    // display overloaded on whether the object is const or not
    // When do_display completes, the display functions each return the object on which they execute by dereferencing this. In the nonconst version, this points to a nonconst object, so that version of display returns an ordinary (nonconst) reference; the const member returns a reference to const.
    Screen &display(std::ostream &os)
    {
        //  When the nonconst version of display calls do_display, its this pointer is implicitly converted from a pointer to nonconst to a pointer to const
        do_display(os);
        return *this;
    }
    const Screen &display(std::ostream &os) const
    {
        do_display(os);
        return *this;
    }

    // Friendship between Classes
    // It is important to understand that friendship is not transitive. That is, if class Window_mgr has its own friends, those friends have no special access to Screen.
    // friend 没有传递性
    friend class Window_mgr;

    // Making A Member Function a Friend
    // 指定一个成员函数为friend，而不是整个Screen class
    // we must specify the class of which that function is a member
    // 必须指定class名字
    // Window_mgr::clear must have been declared before class Screen
    // Classes and nonmember functions need not have been declared before they are used in a friend declaration. When a name first appears in a friend declaration, that name is implicitly assumed to be part of the surrounding scope. However, the friend itself is not actually declared in that scope
    // 这个clear函数不一定要在这个声明前面声明
    friend void Window_mgr::clear(ScreenIndex);
    // Overloaded Functions and Friendship,如何函数有重载，每个重载的函数都是不一样的，要分别设置friend

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

    // mutable Data Members
    // A mutabledata member is never const, even when it is a member of a const object. Accordingly, a const member function may change a mutable member.
    mutable size_t access_ctr; // may change even in a const object

    // function to do the work of displaying a Screen
    void do_display(std::ostream &os) const { os << contents; }
    // other members as before
};

class Window_mgr
{
public:
    // location ID for each screen on the window
    using ScreenIndex = std::vector<Screen>::size_type;
    // reset the Screen at the given position to all blanks
    void clear(ScreenIndex);

private:
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};
void Window_mgr::clear(ScreenIndex i)
{
    // s is a reference to the Screen we want to clear
    Screen &s = screens[i];
    // reset the contents of that Screen to all blanks
    s.contents = string(s.height * s.width, ' ');
}

// We can explicitly declare a member function as inline as part of its declaration inside the class body. Alternatively, we can specify inline on the function definition that appears outside the class body
inline // we can specify inline on the definition
    Screen &
    Screen::move(pos r, pos c)
{
    pos row = r * width; // compute the row location
    cursor = row + c;    // move cursor to the column within that row
    return *this;        // return this object as an lvalue
}
char Screen::get(pos r, pos c) const // declared as inline in the class
{
    pos row = r * width;      // compute row location
    return contents[row + c]; // return character at the given column
}

void Screen::some_member() const
{
    // It sometimes (but not very often) happens that a class has a data member that we want to be able to modify, even inside a const member function.
    // 即使在一个const 成员函数里也能改变这个object中的成员数据
    ++access_ctr; // keep a count of the calls to any member function
    // whatever other work this member needs to do
}

inline Screen &Screen::set(char c)
{
    contents[cursor] = c; // set the new value at the current cursor location
    return *this;         // return this object as an lvalue
}
inline Screen &Screen::set(pos r, pos col, char ch)
{
    contents[r * width + col] = ch; // set specified location to given value
    return *this;                   // return this object as an lvalue
}

struct First
{
    int memi;
    int getMem();
};
struct Second
{
    int memi;
    int getMem();
};

struct Z
{
    // It is important to understand that a friend declaration affects access but is not a declaration in an ordinary sense.
    // 这只是一个friend授权 而不是一个普通的声明
    friend void f() { /* friend function can be defined in the class body   */ }
    // Z() { f(); } // error: no declaration for f 即使在这个类里面定义了，还要在类外面定义才能使用
    void g();
    void h();
};
// void Z::g() { return f(); } // error: f hasn't been declared
void f();                   // declares the function defined inside Z
void Z::h() { return f(); } // ok: declaration for f is now in scope
int main()
{
    Screen myScreen(5, 5, 'x');
    char ch = myScreen.get(); // 内联函数
    // char ch = myScreen.contents[myScreen.cursor];//error

    // When we call display on an object, whether that object is const determines which version of display is called
    const Screen blank(5, 3);
    myScreen.set('#').display(cout); // calls non const version
    blank.display(cout);             // calls const version

    // 即使两个class type有一样的member也是两个不同的类型
    First obj1;
    // Second obj2 = obj1; // error: obj1 and obj2 have different types

    // Alternatively, we can use the class name following the keyword class or struct
    // Both methods of referring to a class type are equivalent. The second method is inherited from C and is also valid in C++.
    Screen item1; // default-initialized object of type Screen
    // class Screen item1; // equivalent declaration c语言中的方式

    // Just as we can declare a function apart from its definition (§ 6.1.2, p. 206), we can also declare a class without defining it
    class Test; // 只声明不定义 未完成类型 不知道它包含的members
    // We can define pointers or references to such types, and we can declare (but not define) functions that use an incomplete type as a parameter or return type
    Test *pt;

    class Link_screen
    {
        Screen window;
        Link_screen *next;
        Link_screen *prev;
    };

    // exercises
    // Define a pair of classes X and Y, in which X has a pointer to Y, and Y has an object of type X.
    // class X
    // {
    //     Y *py; //error
    // };
    // class Y
    // {
    //     X x;
    // };

    return 0;
}