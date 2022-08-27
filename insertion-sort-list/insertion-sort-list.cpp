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
    ListNode* insertionSortList(ListNode* a) {
        
         if(!a||!a->next)
             return a;
        ListNode *q = a->next, *p , *r ,*h=a;
        while(q)
        {
            p = a;
            r = NULL ;
            while(p->val<q->val&&p!=q)
            {
                r = p;
                p=p->next;
            }
            if(p!=q)
            {
                if(!r)
                {
                    r = q;
                    a = r;
                }
                else
                {
                    r->next  = q;
                    r =r->next;
                }
                q=q->next;
                r->next = p;
                h->next = q;   
            }
            else
            {
                h = q;
                q=q->next;
            }
        }
        return a;
        
    }
};