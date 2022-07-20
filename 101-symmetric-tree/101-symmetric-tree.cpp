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
    
    bool is(TreeNode* a,TreeNode* b)
    {
        if(!a&&!b)
            return 1;
        if(!a||!b)
            return 0;
        if(a->val!=b->val)
            return 0;
        return (is(a->left,b->right)&&is(a->right,b->left));
    }
    
    bool isSymmetric(TreeNode* r) {
        
        if(!r)
            return 1;
        return is(r->left,r->right);
        
        
    }
};