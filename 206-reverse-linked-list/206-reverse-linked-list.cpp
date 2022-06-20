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
        
        ListNode *p = a , *q = a->next , *r = NULL;
        
        while(p)
        {
            p->next = r;
            r = p;
            p = q;
            if(q)
                q=q->next;
        }
        
        return r;
        
    }
};