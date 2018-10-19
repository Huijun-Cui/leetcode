#include <iostream>
#include <stack>


void SortAges(int ages[],int length)
{
    if(ages == nullptr || length <= 0)
        return;
    const int oldestAge = 99;
    int timeofAge[oldestAge + 1];
    for(int i =0;i<=oldestAge;++i)
        timeofAge[i] = 0;
    for(int i =0;i< length;i++)
    {
        int age = age[i];
        if(age <0 || age > oldestAge)
            throw new std::exception('age out of range:');

        ++ timeofAge[age];
    }
    int index = 0;
    for(int i=0;i<=oldestAge;i++)
    {
        ages[index] = i;
        ++index;
    }
}