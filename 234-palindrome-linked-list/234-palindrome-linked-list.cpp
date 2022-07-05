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
    
    bool call(ListNode* a,ListNode **p)
    {
        if(!a)
            return 1;
        
        bool b = call(a->next,p);
        
        if(!b)
            return 0;
        
        if(a->val!=(*p)->val)
            return 0;
        
        (*p) = (*p)->next;
        return 1;
        
    }
    
    bool isPalindrome(ListNode* a) {
        
        ListNode* p = a ;
        
        return call(a,&p);
        
    }
};