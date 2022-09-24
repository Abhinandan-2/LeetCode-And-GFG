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
    
    void call(TreeNode* a,int t,vector<int> &b,vector<vector<int>> &ans,int sum)
    {
        if(!a->left&&!a->right)
        {
            b.push_back(a->val);
            sum+=a->val;
            if(sum==t)
                ans.push_back(b);
            b.pop_back();
            return ;
        }
        
        b.push_back(a->val);
        sum+=a->val;
        if(a->left)
            call(a->left,t,b,ans,sum);
        if(a->right)
            call(a->right,t,b,ans,sum);
        b.pop_back();
        return ;
        
    }
    
    
    vector<vector<int>> pathSum(TreeNode* r, int t) {
        
        vector<vector<int>> ans;
        vector<int> b;
        int sum=0;
        if(!r)
            return ans;
        call(r,t,b,ans,sum);
        return ans;
        
        
        
    }
};