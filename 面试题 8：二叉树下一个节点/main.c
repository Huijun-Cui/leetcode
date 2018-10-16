#include <iostream>
# include <stdio.h>


struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
    if(pNode == NULL)
        return NULL;
    BinaryTreeNode* pNext = NULL;
    if(pNode->m_pRight !=NULL)
    {
        BinaryTreeNode* pRight = pNode->m_pRight;
        while(pRight->m_pRight != NULL)
            pRight = pRight->m_pLeft;
        pNext = pRight;
    }
    else if(pNode->m_pParent!=NULL)
    {
        BinaryTreeNode* pCurrent = pNode;
        BinaryTreeNode* pParent = pNode->m_pParent;
        while(pParent != NULL && pCurrent == pParent->m_pRight)
        {
            pCurrent = pParent;
            pParent = pParent->m_pParent;
        }

        pNext = pParent;
    }

    return pNext;
}





int main()
{
    int pre_data[8] = {1,2,4,7,3,5,6,8};
    int in_data[8] = {4,7,2,1,5,3,8,6};
    Construct(pre_data,in_data,8);
}