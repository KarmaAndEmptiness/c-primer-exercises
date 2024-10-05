#include <iostream>
#include <vector>
#include <string>
#include "../Sales_item.h"
using std::cout;
using std::endl;
using std::string;
using std::vector;
string wordToUpper(string &word);
int main()
{
    // Ways to Initialize a vector
    using T = int;
    const int n = 10, val = 10, a = 1, b = 2, c = 3;
    vector<T> vec1;                      // vector that holds objects of type T. Default initialization; vec1 is empty.
    vector<T> vec2(vec1);                // vec2 has a copy of each element in vec1.
    vector<T> vec3 = vec1;               // Equivalent to vec3(vec1), vec3 is a copy of the elements in vec1.
    vector<T> vec4(n, val);              // vec4 has n elements with value val.
    vector<T> vec5(n);                   // vec5 has n copies of a value-initialized object.
    vector<T> vec6{a, b, c, /*...*/};    // vec6 has as many elements as there are initializers; elements are initialized by corresponding initializers.
    vector<T> vec7 = {a, b, c, /*...*/}; // Equivalent to vec6 {a, b, c, ...}.

    // Templates are not themselves functions or classes. Instead, they can be thought of as instructions to the compiler for generating classes or functions.
    // vector is a template, not a type. Types generated from vector must include the element type, for example, vector<int>.
    vector<int>
        ivec;                     // ivec holds objects of type int
    vector<Sales_item> Sales_vec; // holds Sales_items
    vector<vector<string>> file;  // vector whose elements are vectors

    vector<string> svec; // default initialization; svec has no elements

    vector<int> ivec1; // initially empty
    // give ivec some values
    vector<int> ivec2(ivec1); // copy elements of ivec into ivec2
    vector<int> ivec3 = ivec; // copy elements of ivec into ivec3
    // vector<string> svec1(ivec2); // error: svec1 holds strings, not ints

    //  third restriction is that we can supply a list of element values only by using list initialization in which the initializers are enclosed in curly braces. We cannot supply a list of initializers using parentheses
    vector<string> articles = {"a", "an", "the"}; // List Initializing a vector
    // vector<string> v2("a", "an", "the");  // error

    // ivec1 = 10;

    vector<int> v1(10);    // v1 has ten elements with value 0
    vector<int> v2{10};    // v2 has one element with value 10
    vector<int> v3(10, 1); // v3 has ten elements with value 1
    vector<int> v4{10, 1}; // v4 has two elements with values 10 and 1

    // n this case, there is no confusion about whether to list initialize the elements or construct a vector of the given size
    vector<string> v5{"hi"}; // list initialization: v5 has one element
    // vector<string> v6("hi");     // error: can't construct a vector from a string literal

    // Although we used braces on all but one of these definitions, only v5 is list initialized. In order to list initialize the vector, the values inside braces must match the element type. We cannot use an int to initialize a string, so the initializers for v7 and v8 can’t be element initializers.If list initialization isn’t possible, the compiler looks for other ways to initialize the object from the given values.
    vector<string> v7{10};       // v7 has ten default-initialized elements
    vector<string> v8{10, "hi"}; // v8 has ten elements with value "hi"

    vector<string> v9(10);
    vector<string> v10(10, "hi");

    // To use size_type, we must name the type in which it is defined. A vector type always includes its element type
    vector<int>::size_type len = 0; // ok
    // vector::size_type       // error

    // The relational operators apply a dictionary ordering: If the vectors have differing sizes, but the elements that are in common are equal, then the vector with fewer elements is less than the one with more elements. If the elements have differing values, then the relationship between the vectors is determined by the relationship between the first elements that differ.
    vector<int> v11 = {1, 3, 5, 7};
    vector<int> v12 = {1, 3, 5};
    vector<int> v13 = {2, 4, 6};
    vector<int> v14 = {1, 3, 5, 7};
    cout << "v11 > v12: " << (v11 > v12) << endl
         << "v11 > v13: " << (v11 > v13) << endl
         << "v11 == v12: " << (v11 == v12) << endl
         << "v11 == v13: " << (v11 == v13) << endl
         << "v11 == v14: " << (v11 == v14) << endl;

    // We can compare two vectors only if we can compare the elements in those vectors. Some class types, such as string, define the meaning of the equality and relational operators. Others, such as our Sales_item class, do not. The only operations Sales_item supports are those listed in § 1.5.1 (p. 20). Those operations did not include the equality or relational operators. As a result, we cannot compare two vector<Sales_item> objects.
    vector<string> sv1{"hello", "world"};
    vector<string> sv2{"hello"};
    vector<string> sv3{"world"};
    vector<string> sv4 = sv1;
    cout << "sv1 > sv2: " << (sv1 > sv2) << endl
         << "sv1 > sv3: " << (sv1 > sv3) << endl
         << "sv1 == sv4: " << (sv1 == sv4) << endl;

    // vector<Sales_item> ss1("abc");

    vector<int> temp = {11, 20, 50, 70, 30, 60, 100, 45, 33, 26, 19, 88, 43};
    // count the number of grades by clusters of ten: 0--9, 10--19, . .. 90--99, 100
    vector<unsigned> scores(11, 0); // 11 buckets, all initially 0
    unsigned grade;
    for (int i = 0; i < temp.size(); i++)
    {
        grade = temp[i];
        if (grade <= 100)         // handle only valid grades
            ++scores[grade / 10]; // c语言里面也可以使用。 increment the counter for the current cluster. The statement that does the increment is a good example of the kind of terse code characteristic of C++ programs.
    }

    for (const auto &count : scores)
    {
        cout << count << " ";
    }
    cout << endl;

    vector<int> ivec4; // empty vector
    // for (decltype(ivec4.size()) ix = 0; ix != 10; ++ix)
    // ivec[ix] = ix; // disaster: ivec has no elements.The subscript operator on vector (and string) fetches an existing element; it does not add an element.

    // exercise
    int count = 0;
    string word;
    vector<string> words = {"hello", "world", "welcome", "to", "my", "home", "nice", "to", "meet", "you"};
    for (auto &temp : words)
    {
        temp = wordToUpper(temp);
    }
    for (const auto &temp : words)
    {
        cout << temp << " ";
        count++;
        if (count % 8 == 0 && count != 0)
            cout << endl;
    }
    cout << endl;
    return 0;
}
string wordToUpper(string &word)
{
    for (auto &c : word)
        c = toupper(c);
    return word;
}