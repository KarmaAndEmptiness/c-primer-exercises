#include <string>
#include <vector>
#include <stack>
using std::stack;
using std::string;
using std::vector;
int main()
{
    // By default both stack and queue are implemented in terms of deque, and a priority_queue is implemented on a vector. We can override the default container type by naming a sequential container as a second type argument when we create the adaptor
    // empty stack implemented on top of vector
    stack<string, vector<string>> str_stk;

    // str_stk2 is implemented on top of vector and initially holds a copy of svec
    vector<string> svec;
    stack<string, vector<string>> str_stk2(svec);

    stack<int> intStack; // empty stack
    // fill up the stack
    for (size_t ix = 0; ix != 10; ++ix)
        intStack.push(ix); // intStackholds 0 ... 9 inclusive
    while (!intStack.empty())
    { // while there are still values in intStack
        int value = intStack.top();
        // code that uses value
        intStack.pop(); // pop the top element, and repeat
    }

    return 0;
}