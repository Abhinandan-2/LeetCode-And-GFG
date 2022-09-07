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
    
    void preordered(TreeNode *a,string &ans)
    {
        ans += to_string(a->val);
        if(a->right)
        {
            ans.push_back('(');
            if(a->left)
            preordered(a->left,ans);
            ans.push_back(')');
            ans.push_back('(');
            preordered(a->right,ans);
            ans.push_back(')');
            return ;
        }
        if(a->left)
        {
            ans.push_back('(');
            preordered(a->left,ans);
            ans.push_back(')');
        }
        return ;  
    }
    
public:
    
    
    string tree2str(TreeNode* a) {
        
        string ans;
        
        preordered(a,ans);
        
        return ans;
        
        
    }
};