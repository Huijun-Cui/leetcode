;row < rows;++row)
    {
        for(int col = 0;col <cols;++col)
        {
            if(hasPathCore(matrix,rows,cols,row,col,str,pathLength,visited))
                return true;
        }
    }
    delete[] visited;
    return false;
}

bool hasPathCore(const char* matrix,int rows,int cols,int row,int col, const char* str,
        int& pathLength,bool* visited)
{
    if(str[pathLength] == '\0')
        return true;
    bool hashPath = false;
    if(row>=0&&row<rows&&col>=0&&col<cols&&matrix[row*cols+col]==str[pathLength]&&!visited[row*cols+col])
    {
        ++pathLength;
        visited[row*cols + col] = true;
        hashPath = hashPathCore(matrix,rows,cols,row,col-1,str,pathLength,visited)
                || hashPathCore(matrix,rows,cols,row-1,col,str,pathLength,visited)
                || hashPathCore(matrix,rows,cols,row,col+1,str,pathLength,visited)
                || hashPathCore(matrix,rows,cols,row + 1,col,str,pathLength,visited);
    }

    if(!hashPath)
    {
        --pathLength;
        visited[row*cols +col] = false;
    }

    return hashPath
}