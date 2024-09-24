#include <iostream>
#include "Sales_item.h"
int main()
{
    // Sales_item item1, item2;
    // std::cin >> item1 >> item2;
    // std::cout << item1 + item2 << std::endl;
    // Sales_item item;
    // while (std::cin >> item)
    // {
    //     std::cout << item << std::endl;
    // }
    Sales_item val, currVal;
    int cnt = 0;
    if (std::cin >> currVal)
    {
        cnt = 1;
        while (std::cin >> val)
        {
            if (val.isbn() == currVal.isbn())
                cnt++;
            else
            {
                std::cout << "isbn: " << currVal.isbn() << " occurs " << cnt << " times" << std::endl;
                cnt = 1;
                currVal = val;
            }
        }
        std::cout << "isbn: " << currVal.isbn() << " occurs " << cnt << " times" << std::endl;
    }

    return 0;
}