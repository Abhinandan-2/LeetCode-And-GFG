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
    
    void call(ListNode* a,vector<int> &ans,stack<int> &s)
    {
        if(a)
        {
            call(a->next,ans,s);
            while(!s.empty()&&s.top()<=a->val)
                s.pop();
            if(s.empty())
                ans.push_back(0);
            else
                ans.push_back(s.top());
            s.push(a->val);
        }
        return ;
    }
    
    vector<int> nextLargerNodes(ListNode* a) {
        
        vector<int> ans;
        stack<int> s;
        call(a,ans,s);
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};