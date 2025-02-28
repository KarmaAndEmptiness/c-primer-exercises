#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
class Account
{
public:
    // member functions can use static members directly, without the scope operator
    void calculate() { amount += amount * interestRate; }
    // 在 static 成员函数 中，不仅不能显式地使用 this 指针，也无法通过隐式的 this 指针调用 非静态成员函数。
    static double rate() { return interestRate; }
    static void rate(double);

private:
    std::string owner;
    double amount;
    // The keyword appears only with the declaration inside the class body
    static double interestRate;
    static double initRate();

    static constexpr int period = 30; // period is a constant expression
    double daily_tbl[period];
};
// If an initializer is provided inside the class, the member’s definition must not specify an initial value
// definition of a static member with no initializer
constexpr int Account::period; // initializer provided in the class definition

//  When we define a static member outside the class, we do not repeat the static keyword. The keyword appears only with the declaration inside the class body
void Account::rate(double newRate)
{
    interestRate = newRate;
}

double Account::initRate()
{
    return 0;
}

// Once the class name is seen, the remainder of the definition is in the scope of the class. As a result, we can use initRate without qualification as the initializer for rate
// define and initialize a static class member
double Account::interestRate = initRate();

// In particular, a static data member can have the same type as the class type of which it is a member. A nonstatic data member is restricted to being declared as a pointer or a reference to an object of its class
class Bar
{
public:
    // ...
private:
    static Bar mem1; // ok: static member can have incomplete type
    Bar *mem2;       // ok: pointer member can have incomplete type
    // Bar mem3;        // error: data members must have complete type
};

// Another difference between static and ordinary members is that we can use a static member as a default argument
class Screen
{
public:
    // bkground refers to the static member
    // declared later in the class definition
    // Using a nonstatic data member as a default argument provides no object from which to obtain the member’s value and so is an error
    //默认参数需要在编译时确定其值
    Screen &clear(char = bkground);
    Screen &test(int = 1);
    // Screen &clear(char a = this->t);

private:
    static const char bkground;

    // we can provide in-class initializers for static members that have const integral type and must do so for static members that are constexprs of literal type
    // static char t = 'a';
    // static int a = 3;
    static const int a = 3;
    static constexpr int b = 2;
    static const char t = 'a';
    static constexpr char c = '1';
    // static const double pi = 3.14;
    static constexpr double pi = 3.14;
    // static constexpr string hello = "hello";
};
// char Screen::t;
// int Screen::a;
int main()
{
    // Using a Class static Member
    // We can access a static member directly through the scope operator
    double r;
    r = Account::rate(); // access a static member using the scope operator
    /*
    Account::calculate();
    */
    //    Even though static members are not part of the objects of its class, we can use an object, reference, or pointer of the class type to access a static member
    Account ac1;
    Account *ac2 = &ac1;
    // equivalent ways to call the static member rate function
    r = ac1.rate();  // through an Account object or reference
    r = ac2->rate(); // through a pointer to an Account object

    static int b = 0;

    // static data members are defined outside any function
    // double Account::interestRate = initRate();
    return 0;
}