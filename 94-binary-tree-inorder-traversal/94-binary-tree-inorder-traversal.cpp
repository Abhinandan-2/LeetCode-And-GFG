/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* a) {
        
        stack<TreeNode*> s;
        vector<int> ans;
        if(!a)
            return ans;
        s.push(a);
        TreeNode *p = a;
        while(!s.empty())
        {
            if(p)
            {
                p=p->left;
                if(p)
                    s.push(p);
            }
            else
            {
                p = s.top();
                s.pop();
                ans.push_back(p->val);
                p=p->right;
                if(p)
                    s.push(p);
            }
        }
        return ans;
        
    }
};