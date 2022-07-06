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
    
    ListNode* merge(ListNode* a,ListNode* b)
    {
        if(!a)
            return b;
        if(!b)
            return a;
        
        if(a->val>b->val)
            swap(a,b);
        
        ListNode *p =a , *q = b, *r;
        
        while(p&&q)
        {
            if(p->val<=q->val)
            {
                r = p;
                p=p->next;
            }
            else
            {
                r->next = q;
                r=r->next;
                q=q->next;
                r->next = p;
            }
        }
        
        if(!p)
            r->next = q;
        return a;
        
        
    }
    
    ListNode* mergeSort(ListNode *a)
    {
        if(!a||!a->next)
            return a;
        
        ListNode *p = a ,*q = a->next->next,*b;
        while(q&&q->next)
        {
            q=q->next->next;
            p=p->next;
        }
        b = p->next;
        // cout<<a->val<<" "<<b->val<<endl;
        p->next = NULL;
        ListNode *left = mergeSort(a);
        ListNode *right = mergeSort(b);
        // cout<<left->val<<" "<<right->val<<endl;
        ListNode *ans = merge(left,right);
       
        return ans;
        
        
    }
    
    ListNode* sortList(ListNode* a) {
        
        if(!a||!a->next)
            return a;
        
        
        ListNode* ans = mergeSort(a);
        
        return ans;
        
        
        
    }
};