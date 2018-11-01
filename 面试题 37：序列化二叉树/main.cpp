
struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

void Deserialize(BinaryTreeNode** pRoot,istream& stream)
{
    int number;
    if(ReadStream(stream,&number))
    {
        *pRoot = new BinaryTreeNode();
        (*pRoot)->m_nValue = number;
        (*pRoot)->m_pLeft = nullptr;
        (*pRoot)->m_pRight = nullptr;


        Deserialize(&((*pRoot)->m_pLeft),stream);
        Deserialize(&(*pRoot)->m_pRight,stream);
    }
}