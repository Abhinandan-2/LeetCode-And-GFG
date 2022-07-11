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
    
    void inorder(TreeNode* a,int &k,int &ans)
    {
        if(a&&ans==-1)
        {
            inorder(a->left,k,ans);
            k--;
            if(k==0)
                ans = a->val;
            inorder(a->right,k,ans);
        }
        return ;
    }
    
public:
    int kthSmallest(TreeNode* a, int k) {
        
        int ans = -1;
        
        inorder(a,k,ans);
        
        return ans;
        
    }
};