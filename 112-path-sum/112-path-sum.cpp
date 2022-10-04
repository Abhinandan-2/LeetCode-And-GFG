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
    bool hasPathSum(TreeNode* a, int t) {

        if(!a)
            return 0;
        
        if(!a->left&&!a->right)
        {
            if(a->val==t)
                return 1;
            return 0;
        }
        
        return hasPathSum(a->left,t-a->val)||hasPathSum(a->right,t-a->val);
        
        
        
    }
};