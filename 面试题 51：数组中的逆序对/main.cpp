
(int i=0;i<length;++i)
        copy[i] = data[i];
    int count = InversePairsCore(data,copy,0,length -1);
    delete[] copy;
}

int InversePairsCore(int* data,int* copy,int start,int end)
{
    if(start == end)
    {
        copy[start] = data[start];
        return 0;
    }
    int length = (end - start) / 2;
    int left = InversePairsCore(copy,data,start,start + length);
    int right = InversePairsCore(copy,data,star+length + 1,end);
    int i = start + length;
    int j = end;
    int indexCopy = end;
    int count = 0;
    while(i >= start && j >=start + length + 1)
    {
        if(data[i] > data[j])
        {
            copy[indexCopy--] = data[i--];
            count += j - start - length;
        }
        else
        {
            copy[indexCopy--] = data[j--];
        }
    }
    for(;i>=start;--i)
        copy[indexCopy--] = data[i];
    for(;j>=start + length + 1;--j)
        copy[indexCopy--] = data[j];
    return left + right + count;
}
