#include <iostream>
#include <stack>


int NumberOf1(int n)
{
    int count = 0;
    unsigned int flag = 1;
    while(flag)
    {
        if(n&flag)
            count +=1;
        flag = flag <<1;
    }
    return count;
}