#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <cstring>
using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::vector;
string sa[10];
int ia[10];

int max(int a, int b);
int str_compare(const char *s1, const char *s2);

int main()
{
    //  the dimension must be known at compile time, which means that the dimension must be a constant expression
    unsigned cnt = 42;          // not a constant expression
    constexpr unsigned sz = 42; // constant expression
                                // constexpr see § 2.4.4 (p. 66)
    int arr[10];                // array of ten ints
    int *parr[sz];              // array of 42 pointers to int
    // string bad[cnt];            // error: cnt is not a constant expression
    // string strs[get_size()];    // ok if get_size is constexpr, error otherwise

    // We cannot use auto to deduce the type from a list of initializers.
    // auto arr[10];

    // No Copy or Assignment
    int a[] = {0, 1, 2}; // array of three ints
    // int a2[] = a;        // error: cannot initialize one array with another
    // a2 = a;              // error: cannot assign one array to another

    int *ptrs[10]; //  ptrs is an array of ten pointers to int
    // int &refs[10] = /* ? */; //  error: no arrays of references
    int(*Parray)[10] = &arr; //  Parray points to an array of ten ints
    int(&arrRef)[10] = arr;  //  arrRef refers to an array of ten ints

    int ia[4 * 7 - 14];

    {
        string sa[10];
        int ia[10];
        for (int i = 0; i < 10; i++)
        {
            cout << "ia[" << i << "]: " << ia[i] << " sa[" << i << "]: " << sa[i] << endl;
        }
        cout << endl;
    }

    {
        for (int i = 0; i < 10; i++)
        {
            cout << "ia[" << i << "]: " << ia[i] << " sa[" << i << "]: " << sa[i] << endl;
        }
        cout << endl;
    }

    for (auto &&i : a)
    {
        cout << i << " ";
    }
    cout << endl;
    {
        size_t n;
        cin >> n;
        // constexpr size_t array_size = n;
        int arr[n];
    }
    {
        unsigned scores[11] = {}; // 11 buckets, all value initialized to 0
    }
    {
        int a[10];
        vector<int> vec(10);
        for (int i = 0; i < 10; i++)
        {
            a[i] = i;
        }

        for (size_t i = 0; i < vec.size(); i++)
        {
            vec[i] = i;
        }
    }

    // arrays have a special property—in most places when we use an array, the compiler automatically substitutes a pointer to the first element
    string nums[] = {"one", "two", "three"}; // array of strings
    string *p = &nums[0];                    // p points to the first element in nums
    string *p2 = nums;                       // equivalent to p2 = &nums[0]

    {
        // One such implication is that when we use an array as an initializer for a variable defined using auto, the deduced type is a pointer, not an array
        int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // ia is an array of ten ints
        auto ia2(ia);                              // ia2 is an int* that points to the first element in ia
        // ia2 = 42;                                  // error: ia2 is a pointer, and we can't assign an int to a pointer

        // It is worth noting that this conversion does not happen when we use decltype.The type returned by decltype(ia) is array of ten ints
        int temp = 10;
        // ia3 is an array of ten ints
        decltype(ia) ia3 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        // ia3 = p;       // error: can't assign an int* to an array
        ia3[4] = temp; // ok: assigns the value of temp to an element in ia3
    }

    {
        int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // ia is an array of ten ints
        int *beg = begin(ia);                      // pointer to the first element in ia
        int *last = end(ia);                       // pointer one past the last element in ia
        ptrdiff_t ptrdiff = last - beg;
    }

    {
        string s1 = "A string example";
        string s2 = "A different string";
        if (s1 < s2) // false: s2 is less than s1
            ;
        const char ca1[] = "A string example";
        const char ca2[] = "A different string";
        // if (ca1 < ca2) // undefined: compares two unrelated addresses

        // That function returns 0 if the strings are equal, or a positive or negative value, depending on whether the first string is larger or smaller than the second
        if (strcmp(ca1, ca2) < 0) // same effect as string comparison s1 < s2
            ;
    }

    {
        char ca1[] = {'h', 'i', '\0'};
        char ca2[] = {'y', 'o', 'u', '\0'};
        size_t len = strlen(ca1) + strlen(ca2); // 中间加了一个space，所以不用减一
        char largeStr[len];

        // disastrous if we miscalculated the size of largeStr
        strcpy(largeStr, ca1); // copies ca1 into largeStr
        strcat(largeStr, " "); // adds a space at the end of largeStr
        strcat(largeStr, ca2); // concatenates ca2 onto largeStr

        cout << largeStr << " " << strlen(largeStr) << endl;
    }

    // exercise
    const char s1[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    const char s2[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    const char s3[] = {'h', 'e', 'l', '\0'};
    const char s4[] = {'h', 'i', '\0'};
    cout << "str_compare(s1,s2): " << str_compare(s1, s2) << endl
         << "str_compare(s1,s3): " << str_compare(s1, s3) << endl
         << "str_compare(s1,s4): " << str_compare(s1, s4) << endl;

    {
        string s("some string");
        const char temp[] = {' ', 'h', 'i', '\0'};
        //  That is, it returns a pointer to the beginning of a null-terminated character array that holds the same data as the characters in the string.
        const char *str = s.c_str(); // ok.The name c_str indicates that the function returns a C-style character string
        s += temp;
        cout << "s: " << s << endl;
        // char *str = s; // error: can't initialize a char* from a string
        cout << "str: " << str << endl;
    }

    // Using an Array to Initialize a vector
    int int_arr[] = {0, 1, 2, 3, 4, 5};
    // ivec has six elements; each is a copy of the corresponding element in int_arr
    vector<int> ivec(begin(int_arr), end(int_arr));

    return 0;
}

int max(int a, int b)
{
    if (a < b)
        return b;
    return a;
}

int str_compare(const char *s1, const char *s2)
{
    for (size_t i = 0; i < max(strlen(s1), strlen(s2)); i++)
    {
        if (i == strlen(s1) && i != strlen(s2))
            return -1;
        if (i == strlen(s2) && i != strlen(s1))
            return 1;
        if (s1[i] < s2[i])
            return -1;
        if (s1[i] > s2[i])
            return 1;
    }
    return 0;
}