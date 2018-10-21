#include <iostream>
#include <map>
#include <vector>
#include <typeinfo>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode preHead(0),*p = &preHead;
        int cf = 0;
        while(l1 || l2 || cf)
        {
            if(l1 == nullptr) l1 = new ListNode(0);
            if(l2 == nullptr) l2 = new ListNode(0);
            int sum = l1->val + l2->val;
            cf = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;

        }
        return preHead.next;

    };
};
