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
    ListNode* deleteMiddle(ListNode* a) {
        if(!a||!a->next) return NULL;
        ListNode *p = a , *q = a->next->next;
        while(q&&q->next){
            p=p->next;
            q = q->next->next;
        }
        p->next = p->next->next;
        return a;
        
    }
};