#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
struct Sales_data
{
    // new members: operations on Sales_data objects
    // Functions defined in the class are implicitly inline
    //  After all, the body of isbn doesn’t change the object to which this points, so our function would be more flexible if this were a pointer to const
    std::string isbn() const { return bookNo; }
    // std::string isbn(const Sales_data *const this);

    Sales_data &combine(const Sales_data &);
    double avg_price() const; // 这个const是 this这个指针指向的object的const
    // data members are unchanged
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    // When we create a const object of a class type, the object does not assume its “constness” until after the constructor completes the object’s initialization. Thus, constructors can write to const objects during their construction.
    // Sales_data() const{}
    // If we define any constructors, the class will not have a default constructor unless we define that constructor ourselves.
    // 这里的只有一个构造函数了，编译器默认生成的那个无参的构造函数没有了
    // The compiler generates a default constructor automatically only if a class declares no constructors.
    // Sales_data(const string &) {}

    // constructors added
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {}
    Sales_data(std::istream &);
};

// pseudo-code illustration of how the implicit this pointer is used
// this code is illegal: we may not explicitly define the this pointer ourselves
// note that this is a pointer to const because isbn is a const member
// std::string Sales_data::isbn(const Sales_data *const this)
// {
//     return this->isbn;
// }
Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold; // add the members of rhs into
    revenue += rhs.revenue;       // the members of ''this'' object
    return *this;                 // return the object on which the function was called
}
// nonmember Sales_data interface functions
Sales_data add(const Sales_data &, const Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);

// exercises
Sales_data add(const Sales_data &s1, const Sales_data &s2)
{

    // If we define any constructors, the class will not have a default constructor unless we define that constructor ourselves.
    // 这里的只有一个构造函数了，编译器默认生成的那个无参的构造函数没有了
    // Sales_data res;//error
    Sales_data res("a");
    res.revenue = s1.revenue + s2.revenue;
    return res;
}
std::ostream &print(std::ostream &out, const Sales_data &s)
{
    return out << "bookNo: " << s.bookNo << "  units_sold: " << s.units_sold << "  revenue: " << s.revenue << endl;
}
std::istream &read(std::istream &in, Sales_data &s)
{
    return in >> s.bookNo >> s.units_sold;
}

// For example, if a class has a member that has a class type, and that class doesn’t have a default constructor, then the compiler can’t initialize that member. For such classes, we must define our own version of the default constructor. Otherwise, the class will not have a usable default constructor.
class Engine
{
public:
    Engine(const std::string &type)
    {
        this->type = type; // Engine 必须通过带参数的构造函数来初始化
    }

    void start() const
    {
        std::cout << "The " << type << " engine is starting." << std::endl;
    }

private:
    std::string type;
};

class Car
{
public:
    // 编译器不能合成默认构造函数，因为 Engine 没有默认构造函数
    Car()
    {
        // 必须手动调用 Engine 的构造函数
        // engine = Engine("V8"); // 初始化 Engine 对象
    }

    void drive() const
    {
        // engine.start(); // 调用 Engine 对象的 start() 方法
    }

private:
    // Engine engine; // Engine 类型的成员
};
int main()
{
    //  Copy, Assignment, and Destruction
    // If we do not define these operations, the compiler will synthesize them for us. Ordinarily, the versions that the compiler generates for us execute by copying, assigning, or destroying each member of the object.
    Engine e1("e1");
    Engine e2("e2");
    e1 = e2;
    e1.start();

    return 0;
}