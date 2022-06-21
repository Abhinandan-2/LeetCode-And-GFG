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
    ListNode *detectCycle(ListNode *a) {
        
        ListNode *n = NULL;
        if(!a||!a->next)
            return n;
        ListNode *p= a->next,*q = a->next->next;
        int f=0;
        while(q&&q->next)
        {
            if(p==q)
            {
                f=1;
                break;
            }
            p=p->next;
            q=q->next->next;
        }
        if(f==0)
            return n;
        n = a;
        while(n!=p)
        {
            n=n->next;
            p=p->next;
        }
        return p;
        
    }
};