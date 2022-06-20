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
    
    ListNode* call(ListNode* a,ListNode** ans)
    {
        if(!a->next)
        {
            *ans = a;
            return a;
        }
        ListNode *p = call(a->next,ans);
        
        p->next = a;
        a->next  = NULL;
        return a;
        
    }
    
    ListNode* reverseList(ListNode* a) {
        
        if(!a||!a->next)
            return a;
        ListNode *ans = NULL;
        call(a,&ans);
        return ans;
        
    }
};