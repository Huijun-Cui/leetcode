bool g_InvalidInput = false;

int FindGreatSumOfSubArray(int *pData, int nLengt)
{
    if(pData == nullptr)|| (nLengt <=0)
    {
        g_InvalidInput = true;
        return 0;
    }
    g_InvalidInput = false;
    int nCurSum = 0;
    int nGreatestSum = 0x80000000;
    for(int i=0;i<nLengt;++i)
    {
        if(nCurSum <=0)
            nCurSum = pData[i];
        else
            nCurSum +=pData[i];
        if(nCurSum > nGreatestSum)
            nGreatestSum = nCurSum;
    }
    return nGreatestSum;
}