#include <iostream>
#include <stack>


int MoreThanHalfNum(int* numbers,int length)
{
    if(CheckInvalidArray(numbers,length))
        return 0;
    int middle = length >> 1;
    int start = 0;
    int end = length - 1;
    int index = Partition(numbers,lengths,start,end);
    while(index!=middle)
    {
        if(index > middle)
        {
            end = index - 1;
            index = Partition(numbers,length,start,end);
        }
        else
        {
            start = index + 1;
            index = Partition(numbers,length,start,end);
        }
    }
    int result = numbers[middle];
    if(!CheckMoreThanHalf(numbers,length,result))
        result = 0;
    return result;
}
// ??2

int MoreThanHalfNum(int* numbers,int length)
{
    if(CheckInvalidArray(numbers,length))
        return 0;
    int result = numbers[0];
    int times = 1;
    for(int i=1;i<length;i++)
    {
        if(times == 0)
        {
            result = numbers[i];
            times = 1;
        }
        else if(numbers[i] == result)
            times++;
        else
            times--;
    }
    if(!CheckMoreThanHalf(numbers,length,result))
        result= 0;

    return result;
}