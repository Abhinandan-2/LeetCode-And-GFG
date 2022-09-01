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
    
    void call(TreeNode *a,int mx,int &ans)
    {
        if(a)
        {
            if(a->val>=mx)
                ans++;
            mx = max(mx,a->val);
            call(a->left,mx,ans);
            call(a->right,mx,ans);
        }
        return ;
    }
    
public:
    int goodNodes(TreeNode* a) {
        
        int mx = INT_MIN, ans =0 ;
        
        call(a,mx,ans);
        
        return ans;
        
    }
};