#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;
class Foo
{
public:
    // A constructor is the copy constructor if its first parameter is a reference to the class type and any additional parameters have default values
    Foo();                     // default constructor
    Foo(const Foo &, int = 1); // copy constructor
    // If that parameter were not a reference, then the call would never succeed—to call the copy constructor, we’d need to use the copy constructor to copy the argument, but to copy the argument, we’d need to call the copy constructor, and so on indefinitely.
    //  这样定义copy构造函数会导致无限递归
    //  Foo(const Foo,int=1); // copy constructor

    // To be consistent with assignment for the built-in types, assignment operators usually return a reference to their left-hand operand
    Foo &operator=(const Foo &); // assignment operator

    // Because it takes no parameters, it cannot be overloaded.
    ~Foo(); // destructor
};
struct Bar
{
    /* data */
    int &a;
};

struct Test
{
    /* data */
    int b;
};

int main()
{
    // When we use direct initialization, we are asking the compiler to use ordinary function matching to select the constructor that best matches the arguments we provide.
    int a(1);
    int b('a');
    // When we use copy initialization, we are asking the compiler to copy the right-hand operand into the object being created, converting that operand if necessary.
    a = 'b';

    // Brace initialize the elements in an array or the members of an aggregate class
    int arr[1] = {a};
    Test test = {a};

    Bar Bar = {a}; // 这个不是copy initialize
    // const int &c[1]={a};

    string dots(10, '.');               // direct initialization
    string s(dots);                     // direct initialization
    string s2 = dots;                   // copy initialization
    string null_book = "9-999-99999-9"; // copy initialization
    string nines = string(100, '9');    // copy initialization

    vector<int> v1(10); // ok: direct initialization
    // vector<int> v2 = 10; // error: constructor that takes a size is explicit
    vector<int> v2 = (vector<int>)10; // explicit
    void f(vector<int>);              // f's parameter is copy initialized
    // f(10);               // error: can't use an explicit constructor to copy an argument
    f(vector<int>(10)); // ok: directly construct a temporary vector from an int

    cout << "a: " << a << endl;
    return 0;
}