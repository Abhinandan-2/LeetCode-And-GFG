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
    
    int call(ListNode *a,int k)
    {
        if(!a)
            return 0;
        
        int h = call(a->next,k);
        
        if(h==k)
        {
            a->next = a->next->next;
        }
        
        return h+1;
        
    }
    
    ListNode* removeNthFromEnd(ListNode* a, int k) {
        
        ListNode* p = a;
        int ans = call(a,k);
        if(ans==k)
            return a->next;
        return a;
        
    }
};