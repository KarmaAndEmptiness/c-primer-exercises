#include <iostream>
#include <string>
#include <vector>
#include <memory>
using std::cout;
using std::endl;
using std::make_shared;
using std::string;
using std::vector;
class Sales_data
{
private:
    string bookNo;
};

class Foo
{
public:
    // A constructor is the copy constructor if its first parameter is a reference to the class type and any additional parameters have default values
    Foo() = default; // default constructor
    // Foo(const Foo &, int = 1)=default; // copy constructor,这里不能使用default
    Foo(const Foo &) = default; // copy constructor
    // If that parameter were not a reference, then the call would never succeed—to call the copy constructor, we’d need to use the copy constructor to copy the argument, but to copy the argument, we’d need to call the copy constructor, and so on indefinitely.
    //  这样定义copy构造函数会导致无限递归
    //  Foo(const Foo,int=1); // copy constructor

    // To be consistent with assignment for the built-in types, assignment operators usually return a reference to their left-hand operand
    Foo &operator=(const Foo &) = default; // assignment operator

    // Because it takes no parameters, it cannot be overloaded.
    ~Foo(); // destructor
};

//  If we do not want the synthesized member to be an inline function, we can specify = default on the member’s definition
Foo::~Foo() = default;

struct Bar
{
    /* data */
    int &a;
};

struct Test
{
    /* data */
    const int b;
};

struct X
{
    X() { std::cout << "X()" << std::endl; }
    X(const X &) { std::cout << "X(const X&)" << std::endl; }
    X &operator=(const X &)
    {
        cout << "X& operator=(const X&)" << endl;
        return *this;
    }
    ~X() { cout << "~X()" << endl; }
};

void func(const X x)
{
}

void f(vector<int> vec)
{
}

struct NoCopy
{
    NoCopy() = default;                         // use the synthesized default constructor
    NoCopy(const NoCopy &) = delete;            // no copy
    NoCopy &operator=(const NoCopy &) = delete; // no assignment
    ~NoCopy() = default;                        // use the synthesized destructor
    // other members
};
struct NoDtor
{
    NoDtor() = default; // use the synthesized default constructor
    ~NoDtor() = delete; // we can't destroy objects of type NoDtor
    int a;
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

    Bar bar = {a}; // 这个不是copy initialize
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

    // The destructor is not run when a reference or a pointer to an object goes out of scope.
    { // new scope
        // p and p2 point to dynamically allocated objects
        Sales_data *p = new Sales_data;      // p is a built-in pointer
        auto p2 = make_shared<Sales_data>(); // p2 is a shared_ptr
        Sales_data item(*p);                 // copy constructor copies *p into item
        vector<Sales_data> vec;              // local object
        vec.push_back(*p2);                  // copies the object to which p2 points
        delete p;                            // destructor called on the object pointed to by p
    } // exit local scope; destructor called on item, p2, and vec
      // destroying p2 decrements its use count; if the count goes to 0, the object is freed
      // destroying vec destroys the elements in vec

    cout << "--------------" << endl;
    cout << "X x: " << endl;
    X x;
    cout << "--------------" << endl;
    cout << "func(x): " << endl;
    func(x);
    cout << "--------------" << endl;
    cout << "X *x_ptr: " << endl;
    X *x_ptr = new X;

    cout << "--------------" << endl;
    cout << "delete x_ptr" << endl;
    delete x_ptr;
    cout << "--------------" << endl;
    cout << "vec_X.push_back(x): " << endl;
    vector<X> vec_X;
    vec_X.push_back(x);
    cout << "--------------" << endl;

    // NoDtor nd;  // error: NoDtor destructor is deleted
    NoDtor *p = new NoDtor(); // ok: but we can't delete p
    // delete p; // error: NoDtor destructor is deleted

    //    has a reference member that does not have an in-class initializer
    // Bar bb;//delete constructor

    // The synthesized default constructor is defined as deleted if the class has a member with a deleted or inaccessible destructor;
    // NoDtor noDtor;//error

    // or has a const member whose type does not explicitly define a default constructor and that member does not have an in-class initializer.
    // Test t;//error
    return 0;
}