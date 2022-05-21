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
    
    void call(TreeNode* a,vector<int> &b,vector<vector<int>> &ans)
    {
        if(a)
        {
            b.push_back(a->val);
            if(!a->left&&!a->right)
            {
                ans.push_back(b);
                b.pop_back();
                return ;
            }
            call(a->left,b,ans);
            call(a->right,b,ans);
            b.pop_back();
        }
        return ;
    }
    
    vector<string> binaryTreePaths(TreeNode* a) {
        
        vector<vector<int>> res;
        vector<string> ans;
        if(!a)
            return ans;
        vector<int> b;
        call(a,b,res);
        string k ;
        for(int i=0;i<res.size();i++)
        {
            k.clear();
            for(int j=0;j<res[i].size();j++)
            {
                k += to_string(res[i][j]);
                if(j!=res[i].size()-1)
                    k+= "->";
            }
            ans.push_back(k);
        }
        
        return ans;
        
        
        
    }
};