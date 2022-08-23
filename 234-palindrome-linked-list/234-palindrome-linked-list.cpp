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
    
    bool call(ListNode *a,ListNode **p)
    {
        if(!a)
            return 1;
        
        if(!call(a->next,p))
            return 0;
        
        if(a->val!=(*p)->val)
            return 0;
        (*p)= (*p)->next;
        return 1;
    }
    
public:
    bool isPalindrome(ListNode* a) {
        
        if(!a||!a->next)
            return 1;
        
        ListNode* p = a;
        
        return call(a,&p);
        
        
    }
};