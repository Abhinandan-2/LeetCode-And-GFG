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
    ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
        
        ListNode *p = a,*q = b;
        int f=1,g=1;
        
        while(p&&q&&p!=q)
        {
            p=p->next;
            if(!p&&f==1)
            {
                p=b;
                f=2;
            }
            q=q->next;
            if(!q&&g==1)
            {
                q =a;
                g=2;
            }
        }
        if(p==q)
            return p;
        return NULL;
        
    }
};