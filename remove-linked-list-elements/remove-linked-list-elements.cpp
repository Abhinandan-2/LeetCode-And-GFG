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
    ListNode* removeElements(ListNode* a, int val) {
        
        ListNode * p= a,*q;
        while(p&&p->val==val)
        {
            a= p->next;
            p->next= NULL;
            delete(p);
            p= a;
        }
        if(a==NULL) return a;
        while(p->next)
        {
            if(p->next->val==val)
            {
                q = p->next;
                p->next = q->next;
                q->next = NULL;
                delete(q);
            }
            else
                p=p->next;
        }
        return a;
    }
};