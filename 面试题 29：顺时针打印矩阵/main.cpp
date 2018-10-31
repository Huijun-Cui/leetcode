void PrintMatrixClockwise(int** numbers,int columns,int rows)
{
    if(numbers == nullptr || columns <=0 || rows <=0)
        return;
    int start = 0;
    while(columns >start * 2 && rows > start * 2)
    {
        PrintMatrixInCircle(numbers,columns,rows,start);
        ++start;
    }
}
void PrintMatrixInCircle(int** numvers,int columns,int rows,int start)
{
    int endX = columns -1 - start;
    int endY = rows - 1 - start;
    for(int i = start;i<= endX;++i)
    {
        int number = numbers[start][i];
        printNumber(number);
    }
    if(start < endY)
    {
        for(int i=start +1;i<=endY;++i)
        {
            int number = numbers[i][endX];
            printNumber(number);
        }
    }
    if(start < endX && start < endY)
    {
        for(int i = endX -1;i>=start;i--)
        {
            int number = numbers[endY][i];
            printNumber(number);
        }
    }
    if(start < end && start< endY - 1)
    {
        for(int i = endY -1;i>=start+1;--i)
        {
            int number = numbers[i][start];
            printNumber(number);
        }
    }
}