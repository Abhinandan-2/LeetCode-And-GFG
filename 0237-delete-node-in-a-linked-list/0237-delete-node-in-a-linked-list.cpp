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
    void deleteNode(ListNode* a) {
        
        ListNode *r = NULL;
        do
        {
            a->val = a->next->val;
            r = a;
            a=a->next;
        }
        while(a->next);
        r->next = NULL;
        return ;
        
    }
};