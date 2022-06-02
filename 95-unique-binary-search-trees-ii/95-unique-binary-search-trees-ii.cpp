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
    
    vector<TreeNode*> call(int s,int e,map<pair<int,int>,vector<TreeNode*>> &dp)
    {
        TreeNode* t = NULL;
        if(s>e)
            return {t};
        if(s==e)
        {
            t = new TreeNode(s);
            return {t};
        }
        
        if(dp.count({s,e}))
            return dp[{s,e}];
        vector<TreeNode*> ans,leftNodes,rightNodes;
        for(int i=s;i<=e;i++)
        {
            leftNodes = call(s,i-1,dp);
            rightNodes = call(i+1,e,dp);
            for(int j=0;j<leftNodes.size();j++)
            {
                for(int k=0;k<rightNodes.size();k++)
                {
                    t = new TreeNode(i);
                    t->left = leftNodes[j];
                    t->right = rightNodes[k];
                    ans.push_back(t);
                }
            }
        }
        dp[{s,e}] = ans;
        return ans;
    }
        
    
    
public:
    vector<TreeNode*> generateTrees(int n) {
        
        map<pair<int,int>,vector<TreeNode*>> dp;
        
        vector<TreeNode*> ans = call(1,n,dp);
        return ans;
    }
};