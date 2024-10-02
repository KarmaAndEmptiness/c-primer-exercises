#include <iostream>
#include <string>
int main()
{
    // struct Sales_data
    // { /* ... */
    // } accum, trans, *salesptr;
    // equivalent, but better way to define these objects
    struct Sales_data
    {
        std::string bookNo;
        unsigned units_sold = 0;
        double price = 0.0;
        double revenue = 0.0;
    };
    // Sales_data accum, trans, *salesptr;

    Sales_data data1, data2;
    std::cin >> data1.bookNo >> data1.units_sold >> data1.price;
    std::cin >> data2.bookNo >> data2.units_sold >> data2.price;
    data1.revenue = data1.units_sold * data1.price;
    data2.revenue = data2.units_sold * data2.price;

    if (data1.bookNo == data2.bookNo)
    {
        int totalRevenue = data1.revenue + data2.revenue;
        int totalCnt = data1.units_sold + data2.units_sold;
        // print: ISBN, total sold, total revenue, average price per book
        std::cout << data1.bookNo << " " << totalCnt
                  << " " << totalRevenue << std::endl;
        if (totalCnt != 0)
            int average = totalRevenue / totalCnt;
        else
            std::cout << "(no sales)" << std::endl;
        return 0;
    }
    else
    {
        // transactions weren't for the same ISBN
        std::cerr << "Data must refer to the same ISBN"
                  << std::endl;
        return -1; // indicate failure
    }
}