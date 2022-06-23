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
    vector<vector<int>> levelOrder(TreeNode* a) {
        
        vector<vector<int>> ans;
        if(!a)
            return ans;
        vector<int> v;
        int h;
        queue<TreeNode*> q;
        TreeNode* p ;
        q.push(a);
        while(!q.empty())
        {
            h = q.size();
            while(h--)
            {
                p = q.front();
                q.pop();
                v.push_back(p->val);
                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
            }
            ans.push_back(v);
            v.clear();
        }
        
        return ans;
        
    }
};