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
    ListNode* partition(ListNode* a, int x) {
        
        if(!a)
            return a;
        
        ListNode *e=NULL,*o=NULL,*p = NULL , *q = NULL ;
        
        while(a)
        {
            // cout<<a->val<<" ";
            if(a->val<x)
            {
                if(p==NULL)
                {
                    p=a;
                    e= a;
                }
                else
                {
                    p->next = a;
                    p=p->next;
                }
                
            }
            else
            {
                if(q==NULL)
                {
                    q=a;
                    o=a;
                }
                else
                {
                    q->next = a;
                    q=q->next;
                }
            }
            a=a->next;
        }
        // cout<<e->val<<" "<<o->val;
        if(q)
            q->next = NULL;
        if(!p)
            return o;
        p->next = o;
        // p= e;
        // while(p)
        // {
        //     cout<<p->val<<" ";
        //     p=p->next;
        // }
        return e;
    }
};