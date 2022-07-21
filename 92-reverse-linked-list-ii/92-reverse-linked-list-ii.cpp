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
    ListNode* reverseBetween(ListNode* a, int l, int ri) {
        
        ListNode *p = a, *q , *r=NULL ,*s = NULL,*t;
        
        int h = l-1;
        while(h--)
        {
            s = p;
            p=p->next;
        }
        t = p;
        q = p->next;
        h = ri-l+1;
        while(h--)
        {
            p->next= r;
            r= p;
            p= q;
            if(q)
            q=q->next;
        }
        
        if(s==NULL)
            a= r;
        else
            s->next=r;
        t->next = p;
        
        return a;
        
        
        
        
        
        
        
    }
};