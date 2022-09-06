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
    
    bool solve(TreeNode *a)
    {
        if(!a)
            return 0;
        bool b = solve(a->left);
        bool v = solve(a->right);
        
        if(!b) a->left = NULL;
        if(!v) a->right = NULL;
        
        if(b||v||a->val==1)
            return 1;
        return 0;
    }
    
public:
    TreeNode* pruneTree(TreeNode* a) {
        
        if(solve(a))
            return a;
        TreeNode *ans =NULL;
        return ans;
    }
};