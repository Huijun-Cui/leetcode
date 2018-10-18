

BinaryTreeNode* Construct(int* preorder,int* inorder,int length)
{
    if(preorder == NULL || inorder == NULL || length <=0)
        return NULL;
    return ConstructCore(preorder,preorder + length - 1,inorder,inorder + length -1);

}
BinaryTreeNode* ConstructCore(
        int* startPreorder,int* endPreorder,
        int* startInorder,int* endInorder
        )
{
    int rootValue = startPreorder[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = NULL;
    if(startPreorder == endPreorder)
    {
        if(startInorder == endInorder && *startPreorder == *startInorder)
            return root;
        else
           printf("%s","Mistake");
    }
    int* rootInorder = startInorder;
    while(rootInorder <=endInorder && *rootInorder!=rootValue)
        ++rootInorder;

    if(rootInorder == endInorder && *rootInorder != rootValue)
       printf("%s","Mistake");
    int leftLength = rootInorder - startInorder;
    int* leftPreorderEnd = startPreorder + leftLength;

    if(leftLength > 0)
    {
        root->m_pLeft = ConstructCore(startPreorder+1,leftPreorderEnd,startInorder,rootInorder -1);
    }

    if(leftLength < endPreorder - startPreorder)
    {
        root->m_pRight = ConstructCore(leftPreorderEnd+1,endPreorder,rootInorder+1,endInorder);
    }
    return root;

}
int main()
{
    int pre_data[8] = {1,2,4,7,3,5,6,8};
    int in_data[8] = {4,7,2,1,5,3,8,6};
    Construct(pre_data,in_data,8);
}