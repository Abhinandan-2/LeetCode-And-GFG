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
    vector<int> rightSideView(TreeNode* a) {

        
        int k;
        vector<int> ans, h;
        if(!a)
            return ans;
        queue<TreeNode*> q;
        TreeNode *p;
        q.push(a);
        while(!q.empty())
        {
            k = q.size();
            h.clear();
            while(k--)
            {
                p = q.front();
                q.pop();
                h.push_back(p->val);
                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
            }
            k = h.size();
            ans.push_back(h[k-1]);
        }
        
        return ans;
        
    }
};