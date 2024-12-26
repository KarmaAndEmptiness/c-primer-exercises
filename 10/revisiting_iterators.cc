#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

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

    return 0;
}
