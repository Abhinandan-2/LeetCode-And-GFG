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
    ListNode* removeZeroSumSublists(ListNode* a) {
        
        ListNode *t = new ListNode(0),*q;
        t->next = a;
        a= t;
        unordered_map<int,ListNode*> m;
        m[0] = a;
        ListNode *p = a->next;
        int sum =0;
        
        while(p)
        {
            sum += p->val;
            if(m.count(sum))
            {
                q = m[sum];
                q=q->next;
                while(q!=p)
                {
                    sum += q->val;
                    m.erase(sum);
                    q=q->next;
                }
                sum += q->val;
                m[sum]->next = p->next;
                p->next = NULL;
                p = m[sum]->next;
            }
            else
            {
                m[sum] = p;
                p=p->next;
            }
        }
        
        t = a;
        a=a->next;
        t->next = NULL;
        delete(t);
        return a;
        
    }
};