#include <iostream>
using std::cout;
using std::endl;
int main()
{
    // explicitly initialize only element 0 in each row
    int ia[3][4] = {{1}, {4}, {8}};
    for (auto &&i : ia)
    {
        for (auto &&ii : i)
        {
            cout << ii << " ";
        }
        cout << endl;
    }
    cout << endl;

    // explicitly initialize row 0; the remaining elements are value initialized
    int ix[3][4] = {0, 3, 6, 9};
    for (auto &&i : ix)
    {
        for (auto &&ii : i)
        {
            cout << ii << " ";
        }
    }
    cout << endl;

    int(&row)[4] = ia[1];
    for (auto &&i : row)
    {
        cout << i << " ";
    }
    cout << endl;

    // To use a multidimensional array in a range for, the loop control variable for all but the innermost array must be references.
    // this loop does not write to the elements, yet we still define the control variable of the outer loop as a reference. We do so in order to avoid the normal array to pointer conversion
    for (const auto &row : ia) // for every element in the outer array
        for (auto col : row)   // for every element in the inner array
            cout << col << " ";
    cout << endl;

    // for (auto row : ia) //这里的auto会被编译为int*类型，而不是数组类型。Because row is not a reference, when the compiler initializes row it will convert each array element (like any other object of array type) to a pointer to that array’s first element.
    //     for (auto col : row)

    for (decltype(ia[0]) row : ia)
    {
        for (auto col : row)
        {
            cout << col << " ";
        }
    }
    cout << endl;

    int(*p)[4] = ia; // 定义一个指针，指向数组int ia[3][4];的第一个元素(一个size为4的int数组)。p points to an array of four ints
    for (auto &&i : (*p))
    {
        cout << i << " ";
    }
    cout << endl;

    // With the advent of the new standard, we can often avoid having to write the type of a pointer into an array by using auto or decltype
    // print the value of each element in ia, with each inner array on its own line
    // p points to an array of four ints
    for (auto p = ia; p != ia + 3; ++p)
    {
        // q points to the first element of an array of four ints; that is, q points to an int
        for (auto q = *p; q != *p + 4; ++q)
            cout << *q << ' ';
        cout << endl;
    }
    cout << endl;

    // Type Aliases Simplify Pointers to Multidimensional Arrays

    // using int_array = int[4]; // new style type alias declaration;
    typedef int int_array[4]; // equivalent typedef declaration;

    // print the value of each element in ia, with each inner array on its own line
    for (int_array *p = ia; p != ia + 3; ++p)
    {
        for (int *q = *p; q != *p + 4; ++q)
            cout << *q << ' ';
        cout << endl;
    }
    cout << endl;

    // exercise
    int temp[2][2][2] = {
        {{1, 2}, {3, 4}},
        {{5, 6}, {7, 8}}};
    for (int(&i)[2][2] : temp)
    {
        for (size_t j = 0; j < 2; j++)
        {
            for (int *p = i[j]; p != i[j] + 2; p++)
            {

                cout << (*p) << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    {
        typedef int int_i[2][2];
        for (int_i &i : temp)
        {
            for (size_t j = 0; j < 2; j++)
            {
                for (int *p = i[j]; p != i[j] + 2; p++)
                {
                    cout << (*p) << " ";
                }
            }
        }
        cout << endl;
    }

    {
        for (auto &i : temp)
        {
            for (size_t j = 0; j < 2; j++)
            {
                for (auto p = i[j]; p != i[j] + 2; p++)
                {
                    cout << (*p) << " ";
                }
            }
        }
        cout << endl;
    }

    return 0;
}