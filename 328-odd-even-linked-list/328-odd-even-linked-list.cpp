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
    ListNode* oddEvenList(ListNode* a) {
        
        if(!a||!a->next||!a->next->next)
            return a;
        
        ListNode *p = a, *q = a->next,*odd = a,*even  =a->next;
        
        while(p&&q)
        {
            p->next = q->next;
            p=p->next;
            if(!p)
                break;
            q->next = p->next;
            q=q->next;
        }
        
        p = odd;
        
        while(p->next)
            p=p->next;
        
        p->next = even;
        
        return odd;
        
        
    }
};