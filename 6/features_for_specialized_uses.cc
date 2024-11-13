#include <iostream>
#include <string>
#include <cassert>

// We can “turn off” debugging by providing a #define to define NDEBUG.
#define NDEBUG
using std::cout;
using std::endl;
using std::string;
inline void my_func(int n);
int main()
{
    // However, if a parameter has a default argument, all the parameters that follow it must also have default arguments.
    // 跟在有默认值的形参之后的所有形参都要有默认值
    // void fn(int a, int b = 0, int c); // error: default argument missing for parameter 3 of 'void fn(int, int, int)'
    // fn(,1,2);
    void fn(int a, int b = 0, int c = 10);
    fn(1);
    // fn(, , 1); // error: can omit only trailing arguments

    // Local variables may not be used as a default argument.
    int b = 0;
    // void a(int a = b); // error: local variable 'b' may not appear in this context

    // exercises
    int ff(int a, int b = 0, int c = 0); // right
    // char *init(int ht = 24, int wd, char bckgrnd); // error

    char *init(int ht, int wd = 80, char bckgrnd = ' ');
    // init();//error too few arguments
    init(24, 10);
    init(14, '*');

    string make_plural(size_t ctr, const string &word, const string &ending = "s");
    cout << "Singular: " << make_plural(1, "success") << endl;
    cout << "Plural: " << make_plural(2, "success") << endl;

    cout << "Singular: " << make_plural(1, "failure") << endl;
    cout << "Plural: " << make_plural(2, "failure") << endl;

    // We can define shorterString as an inline function by putting the keyword inline before the function’s return type
    // In general, the inline mechanism is meant to optimize small, straight-line functions that are called frequently.
    // The inline specification is only a request to the compiler. The compiler may choose to ignore this request.
    inline void func();

    //  Many compilers will not inline a recursive function. A 75-line function will almost surely not be expanded inline.
    // inline void my_func(int n);
    my_func(74);
    cout << endl;

    // exercises
    inline bool isShorter(const string &s1, const string &s2);

    // The assert macro is often used to check for conditions that “cannot happen.”
    // The behavior of assert depends on the status of a preprocessor variable named NDEBUG. If NDEBUG is defined, assert does nothing. By default, NDEBUG is not defined, so, by default, assert performs a run-time check.
    assert(1 == 0);

    return 0;
}

// The return type and the type of each parameter in a must be a literal type, and the function body must contain exactly one return statement
// In order to be able to expand the function immediately, constexpr functions are implicitly inline.
constexpr int new_sz() { return 42; }
constexpr int foo = new_sz(); // ok: foo is a constant expression

// A constexpr function body may contain other statements so long as those statements generate no actions at run time.
// constexpr 函数中可以包含其它语句 For example, a constexpr function may contain null statements, type aliases, and using declarations.
// scale(arg) is a constant expression if arg is a constant expression
// A constexpr function is not required to return a constant expression.
constexpr size_t scale(size_t cnt) { return new_sz() * cnt; }

void fn(int a, int b = 0, int c = 10)
{
    cout << "a: " << a << "  b: " << b << "  c: " << c << endl;
}
char *init(int ht, int wd = 80, char bckgrnd = ' ')
{
    return nullptr;
}

string make_plural(size_t ctr, const string &word, const string &ending = "s")
{
    return (ctr > 1) ? word + ending : word;
}

inline void my_func(int n)
{
    if (n == 0)
        return;
    cout << n << " ";
    my_func(n - 1);
}

inline bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}