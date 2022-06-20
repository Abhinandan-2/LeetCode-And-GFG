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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        
        ListNode *ans =  NULL , *p = NULL;
        if(!a)
            return b;
        if(!b)
            return a;
        while(a&&b)
        {
            if(a->val>=b->val)
            {
                if(!p)
                {
                    ans = b;
                    p = b;
                    b=b->next;
                    p->next = a;
                }
                else
                {
                    p->next = b;
                    b=b->next;;
                    p=p->next;
                    p->next = a;
                }
            }
            else
            {
                if(!p)
                {
                    ans = a;
                    p = a;
                    a=a->next;
                }
                else{
                p=p->next;
                a=a->next;
                }
            }
        }
        
        if(a)
        {
            return ans;
        }
        
        p->next = b;
        return ans;
            
        
        
        
    }
};