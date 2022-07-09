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
    
    int call(TreeNode* a,int &ans)
    {
        if(a)
        {
            // cout<<a->val<<endl;
            int x = call(a->left,ans);
            int y = call(a->right,ans);
            // cout<<x<<" "<<y<<" "<<a->val<<endl;
            if(x+y+2>ans)
                ans = x+y+2;
            if(y>x)
                return y+1;
            return x+1;
        }
        return -1;
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        int ans = 0 ;
        // cout<<root->val;
        call(root,ans);
        return ans;
        
    }
};