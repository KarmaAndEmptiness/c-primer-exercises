#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
     // The Arithmetic Conversions
     auto a = 3.14;
     // in most expressions, values of integral types smaller than int are first promoted to an appropriate larger integral type.
     short b = 1;
     short c = 2;
     auto d = b + c; // short类型比int类型更小，所以把short类型转换成了int类型
     cout << "sizeof a : " << sizeof a << "  "
          << "sizeof(float): " << sizeof(float) << "  "
          << "sizeof(unsigned long long): " << sizeof(unsigned long long) << "  "
          << "sizeof 3.14f : " << sizeof 3.14f << "  "
          << "sizeof 2ULL : " << sizeof 2ULL << "  "
          // The rules define a hierarchy of type conversions in which operands to an operator are converted to the widest type.
          << "sizeof(3.14f+2ULL): " << sizeof(3.14f + 2ULL) << "  " // 这里没有把float类型转换成unsigned long long类型。More generally, in expressions that mix floating-point and integral values, the integral value is converted to an appropriate floating-point type.
          << "sizeof d: " << sizeof d << endl;

     // Operands of Unsigned Type
     // The integral promotions convert the small integral types to a larger integral type.
     unsigned int e = 1;
     int f = -2;
     unsigned int g = -1;
     long int h = -2;
     float i = 3.14;
     cout << "e+f: " << e + f << "  " // 4294967295 f被转换成了unsigned int类型
          << "g: " << g << "  "       // 4294967295
          << "sizeof(long int): " << sizeof(long int) << "  "
          << "sizeof(long long): " << sizeof(long long) << "  "
          << "sizeof(e+h): " << sizeof(e + h) << "  "
          << "e+h: " << e + h << "  " //-1 h被转换成了long int类型
          << "sizeof(h+i): " << sizeof(h + i) << "  "
          << "h+i: " << h + i << "  " // 1.14 被转换成了float类型
          << endl;

     // Understanding the Arithmetic Conversions
     bool flag;
     char cval;
     short sval;
     unsigned short usval;
     int ival;
     unsigned int uival;
     long lval;
     unsigned long ulval;
     float fval;
     double dval;
     3.14159L + 'a'; //  'a' promoted to int, then that int converted to long double
     dval + ival;    //  ival converted to double
     dval + fval;    //  fval converted to double
     ival = dval;    //  dval converted (by truncation) to int
     flag = dval;    //  if dval is 0, then flag is false, otherwise true
     cval + fval;    //  cval promoted to int, then that int converted to float
     sval + cval;    //  sval and cval promoted to int
     cval + lval;    //  cval converted to long
     ival + ulval;   //  ival converted to unsigned long
     usval + ival;   //  promotion depends on the size of unsigned short and int
     uival + lval;   //  conversion depends on the size of unsigned int and long

     // The type of the result in these expressions is machine dependent.
     cout << "sizeof(3.14159L + 'a') : " << sizeof(3.14159L + 'a') << "  "
          << "sizeof(long double): " << sizeof(long double) << "  "
          << "sizeof(unsigned short): " << sizeof(unsigned short) << "  "
          << endl;

     //  Array to Pointer Conversions: In most expressions, when we use an array, the array is automatically converted to a pointer to the first element in that array
     int ia[10];   // array of ten ints
     int *ip = ia; // convert ia to a pointer to the first element

     const int j = 10;
     const int k = 20;
     const int *pj = &j; // low-level const
     pj = &k;

     // Conversions Defined by Class Types: Class types can define conversions that the compiler will apply automatically.
     string s, t = "a value";   // character string literal converted to type string
     while (1 == 0 && cin >> s) // 只是演示class conversion,不执行cin。 这里的cin转换成了bool类型。
          ;

     // Explicit Conversions
     double l = j / k; // When we do an explicit cast, the warning message is turned off.

     // Any well-defined type conversion, other than those involving low-level const, can be requested using a static_cast.
     int m = 0;
     m = static_cast<int>(l);
     int &n = static_cast<int &>(m);
     // int &o = static_cast<int &>(j); // error, static_cast cannot cast away const or other type qualifiers
     n = 10;
     cout << "m: " << m << endl;

     // A const_cast changes only a low-level const in its operand
     const char *pc = nullptr;
     char *q = const_cast<char *>(pc); // ok: but writing through q is undefined
     const int r = 2;
     int *pr = const_cast<int *>(&r); // Once we have cast away the const of an object, the compiler will no longer prevent us from writing to that object.
     *pr = 20;
     cout << "r: " << r << endl; // 2 *pr=20;没有用

     // exercise
     {
          int i;
          double d;
          const string *ps;
          char *pc;
          void *pv;

          pv = (void *)ps;
          pv = static_cast<void *>(const_cast<string *>(ps));

          i = int(*pc);
          i = static_cast<int>(*pc);
          // i = reinterpret_cast<int>(*pc); // reinterpret_cast 不会更改数据的值或结构，只是告诉编译器将内存中的位模式按照新类型解释

          pv = &d;
          pv = static_cast<void *>(&d);
          pv = reinterpret_cast<void *>(&d);

          pc = (char *)pv;
          pc = static_cast<char *>(pv);
          pc = reinterpret_cast<char *>(pv);
     }

     {
          short i = 1;
          cout << "sizeof (i<<1): " << sizeof(i << 1) << endl; // i 本来是short类型，经过左移操作后被转换成了int类型。The left-shift operator. Shifts bits in a (possibly promoted) copy of the value of the left-hand operand to the left.
     }

     return 0;
}