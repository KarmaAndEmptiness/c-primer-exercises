#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <algorithm>
using std::cout;
using std::endl;
using std::front_insert_iterator;
using std::inserter;
using std::list;
int main()
{
    // 创建一个包含重复元素的 vector
    std::vector<int> vec = {1, 2, 2, 3, 3, 3, 4, 5, 5};

    // 创建一个空的 list 用来存储唯一元素
    std::list<int> lst;

    // 使用 unique_copy 将 vector 中的唯一元素复制到 list 中
    std::unique_copy(vec.begin(), vec.end(), std::back_inserter(lst));

    // 输出 list 中的元素
    std::cout << "Unique elements in list: ";
    for (const int &val : lst)
    {
        std::cout << val << " ";
    }
    cout << endl;

    {

        list<int> lst = {1, 2, 3, 4};
        list<int> lst2, lst3; // empty lists
        // after copy completes, lst2 contains 4 3 2 1
        copy(lst.cbegin(), lst.cend(), front_inserter(lst2));
        // after copy completes, lst3 contains 1 2 3 4
        copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin()));
        cout << "lst2: " << endl;
        for (auto &&i : lst2)
        {
            cout << i << " ";
        }
        cout << endl;
        cout << "lst3: " << endl;
        for (auto &&i : lst3)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
