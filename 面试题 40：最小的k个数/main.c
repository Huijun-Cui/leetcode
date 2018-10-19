#include <iostream>
#include <stack>

void GetLeastNumbers(int* input,int n,int* output,int k)
{
    if(input == nullptr || output == nullptr || k>n|| n<=0||k<=0)
        return;
    int start = 0;
    int end = n - 1;
    int index = Partition(input,n,start,end);
    while(index != k - 1)
    {
        if(index > k- 1)
        {
            end = index - 1;
            index = Partition(input,n,start,end);
        }
        else
        {
            start = index + 1;
            index = Partition(input,n,start,end);
        }
    }
    for(int i=0;i<k;++i)
        output[i] = input[i];
}