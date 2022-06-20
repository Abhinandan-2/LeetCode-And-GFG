/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* a) {
        
        if(!a||!a->next)
            return a;
        
        ListNode *p = reverseList(a->next),*t;
        a->next = NULL;
        t = p ;
        while(t->next)
            t=t->next;
        t->next = a;
        
        return p;
    }
};