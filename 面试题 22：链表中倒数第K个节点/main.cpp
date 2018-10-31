struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
    ListNode* pAhead = pListHead;
    ListNode* pBehind = nullptr;
    for(unsigned int i=0;i<k-1;i++)
    {
        pAhead = pAhead->m_pNext;
    }
    pBehind = pListHead;
    while(pAhead->m_pNext != nullptr)
    {
        pAhead = pAhead->m_pNext;
        pBehind = pBehind->m_pNext;
    }
    return pBehind;
}