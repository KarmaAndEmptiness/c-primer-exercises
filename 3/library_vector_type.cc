#include <iostream>
#include <vector>
#include <string>
#include "../Sales_item.h"
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main()
{
    // Templates are not themselves functions or classes. Instead, they can be thought of as instructions to the compiler for generating classes or functions.
    // vector is a template, not a type. Types generated from vector must include the element type, for example, vector<int>.
    vector<int> ivec;             // ivec holds objects of type int
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

    return 0;
}