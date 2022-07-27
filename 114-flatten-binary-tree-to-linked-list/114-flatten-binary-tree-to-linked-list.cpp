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
    
    TreeNode* flat(TreeNode* a)
    {
        if(!a->left&&!a->right)
            return a;
        if(!a->left)
        {
            TreeNode *right = flat(a->right);
            return right;
        }
        if(!a->right)
        {
            TreeNode *left = flat(a->left);
            a->right = a->left;
            a->left = NULL;
            return left;
        }
        
        TreeNode *left = flat(a->left);
        TreeNode *right = flat(a->right);
        TreeNode *help = a->right;
        a->right = a->left;
        a->left = NULL;
        left->right = help;
        return right;
        
    }
    
public:
    void flatten(TreeNode* root) {
        
        if(!root)
            return ;
        flat(root);
        return ;
        
    }
};