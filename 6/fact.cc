#include "Chapter6.hh"

int fact(int n)
{
    if (n <= 0)
        return 0;
    int ret = 1;
    while (n != 0)
    {
        ret *= n;
        --n;
    }
    return ret;
}