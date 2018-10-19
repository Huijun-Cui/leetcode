#include <iostream>
#include <stack>

int Partition(int data[],int length,int start,int end)
{
    if(data == nullptr || length == 0|| start <0 || end >= length)
        throw new std::exception("Invalid Parameters");
    int index = RandomInRange(start,end);
    Swap(&data[index],&data[end]);
    int small = start - 1;
    for(index = start;index<end;++index)
    {
        if(data[index] < data[end])
        {
            ++small;
            if(small != start)
                Swap(&data[index],&data[small]);
        }
    }
    ++ small;
    Swap(&data[small],&data[end]);
    return  small

}

void QuickSoort(int data[],int length,int start,int end)
{
    if(start == end)
        return;
    int index = Partition(data,length,start,end);
    if(index > start)
        QuickSoort(data,length,start,index-1);
    if(index < end)
        QuickSoort(data,length,index-1,end);

}