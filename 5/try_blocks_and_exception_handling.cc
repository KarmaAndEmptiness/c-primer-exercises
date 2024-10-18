#include <iostream>
#include <stdexcept>
using std::cout;
using std::endl;
using namespace std;
void throw_an_exception()
{
    throw runtime_error("func threw an exception!");
}
int main()
{
    int a = 1, b = 2;
    try
    {
        throw runtime_error("throw an exception!");
    }
    catch (runtime_error err)
    {
        cout << err.what() << endl;
    }

    // Functions Are Exited during the Search for a Handler
    // Exceptions that occur in programs that do not define any try blocks are handled in the same manner: After all, if there are no try blocks, there can be no handlers. If a program has no try blocks and an exception occurs, then terminate is called and the program is exited.

    // throw runtime_error("throw an exception");

    // When an exception is thrown, the function that threw the exception is searched first. If no matching catch is found, that function terminates. The function that called the one that threw is searched next. If no handler is found, that function also exits. That function’s caller is searched next, and so on back up the execution path until a catch of an appropriate type is found.
    try
    {
        throw_an_exception();
    }
    catch (runtime_error e)
    {
        std::cerr << e.what() << '\n';
    }

    int c = 0;
    try
    {
        cout << (1 / 0) << endl;
    }
    catch (const std::runtime_error e)
    {
    }

    // If no appropriate catch is found, execution is transferred to a library function named terminate.
    try
    {

        throw_an_exception();
    }
    catch (length_error e)
    {
    }

    cout << "exit" << endl;

    return 0;
}