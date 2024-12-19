#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
class HasPtrValueLike
{
public:
    HasPtrValueLike(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    // each HasPtrValueLike has its own copy of the string to which ps points
    HasPtrValueLike(const HasPtrValueLike &p) : ps(new std::string(*p.ps)), i(p.i) {}
    HasPtrValueLike &operator=(const HasPtrValueLike &);
    ~HasPtrValueLike() { delete ps; }
    string getString() { return *ps; }

private:
    std::string *ps;
    int i;
};
// Valuelike Copy-Assignment Operator
//  Like the destructor, assignment destroys the left-hand operand’s resources. Like the copy constructor, assignment copies data from the right-hand operand.
HasPtrValueLike &HasPtrValueLike::operator=(const HasPtrValueLike &rhs)
{
    // 这句代码要放在delete前面，防止自我赋值的时候出问题
    auto newp = new string(*rhs.ps); // copy the underlying string
    delete ps;                       // free the old memory
    ps = newp;                       // copy data from rhs into this object
    i = rhs.i;

    return *this; // return this object
}

// HasPtrValueLike &HasPtrValueLike::operator=(const HasPtrValueLike &rhs)
// {
//     string newVal = *(rhs.ps);
//     *ps = newVal;
//     i = rhs.i;
//     return *this; // return this object
// }

// Reference Counts
class HasPtrPointerLike
{
public:
    HasPtrPointerLike(const std::string &s = std::string()) : ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
    // each HasPtr has its own copy of the string to which ps points
    HasPtrPointerLike(const HasPtrPointerLike &p) : ps(p.ps), i(p.i), use(p.use) { ++*use; }
    HasPtrPointerLike &operator=(const HasPtrPointerLike &);
    ~HasPtrPointerLike();

private:
    std::string *ps;
    int i;
    std::size_t *use;
};
HasPtrPointerLike::~HasPtrPointerLike()
{
    if (--*use == 0)
    {               // if the reference count goes to 0
        delete ps;  // delete the string
        delete use; // and the counter
    }
}

HasPtrPointerLike &HasPtrPointerLike::operator=(const HasPtrPointerLike &rhs)
{
    // 处理自赋值,所以放在前面
    ++*rhs.use; // increment the use count of the right-hand operand
    if (--*use == 0)
    {               // then decrement this object's counter
        delete ps;  // if no other users
        delete use; // free this object's allocated members
    }
    ps = rhs.ps; // copy data from rhs into this object
    i = rhs.i;
    use = rhs.use;
    return *this; // return this object
}

// exercise
//  implement a default constructor and the necessary copy-control members.
class TreeNode
{

public:
    // 默认构造函数
    TreeNode(const std::string &v = "", int c = 0)
        : value(v), count(c), left(nullptr), right(nullptr) {}

    // 拷贝构造函数
    TreeNode(const TreeNode &other)
        : value(other.value), count(other.count), left(nullptr), right(nullptr)
    {
        // 如果左子树存在，进行深拷贝
        if (other.left)
        {
            left = new TreeNode(*other.left);
        }
        // 如果右子树存在，进行深拷贝
        if (other.right)
        {
            right = new TreeNode(*other.right);
        }
    }

    // 赋值操作符
    TreeNode &operator=(const TreeNode &other)
    {
        if (this == &other) // 防止自赋值
            return *this;

        // 先删除旧的资源
        delete left;
        delete right;

        // 复制数据成员
        value = other.value;
        count = other.count;

        // 深拷贝左子树
        if (other.left)
        {
            left = new TreeNode(*other.left);
        }
        else
        {
            left = nullptr;
        }

        // 深拷贝右子树
        if (other.right)
        {
            right = new TreeNode(*other.right);
        }
        else
        {
            right = nullptr;
        }

        return *this;
    }

    // 析构函数
    ~TreeNode()
    {
        delete left;  // 删除左子树
        delete right; // 删除右子树
    }

private:
    std::string value;
    int count;
    TreeNode *left;
    TreeNode *right;
};
class BinStrTree
{
    public:
    // 默认构造函数
    BinStrTree() : root(nullptr) {}

    // 拷贝构造函数
    BinStrTree(const BinStrTree& other) : root(nullptr) {
        if (other.root) {
            root = new TreeNode(*other.root);  // 深拷贝树的根节点
        }
    }

    // 赋值操作符
    BinStrTree& operator=(const BinStrTree& other) {
        if (this == &other)  // 防止自赋值
            return *this;

        // 删除原来的树
        delete root;

        // 深拷贝根节点
        if (other.root) {
            root = new TreeNode(*other.root);
        } else {
            root = nullptr;
        }

        return *this;
    }

    // 析构函数
    ~BinStrTree() {
        delete root;  // 删除树的所有节点
    }
private:
    TreeNode *root;
};
int main()
{
    HasPtrValueLike h1("hello");
    HasPtrValueLike h2("world");
    h1 = h1;

    cout << "h1: " << h1.getString() << ", h2: " << h2.getString() << endl;
    return 0;
}