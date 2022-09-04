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
    vector<vector<int>> verticalTraversal(TreeNode* a) {
        
        vector<vector<int>> res;
        
        queue<pair<TreeNode*,int>> q;
        pair<TreeNode*,int> p;
        q.push({a,0});
        int level = 0,i=1;
        while(!q.empty())
        {
            p = q.front();
            q.pop();
            res.push_back({p.second,level,p.first->val});
            if(p.first->left)
                q.push({p.first->left,p.second-1});
            if(p.first->right)
                q.push({p.first->right,p.second+1});
            i--;
            if(i==0)
            {
                i = q.size();
                level++;
            }
        }
        
        sort(res.begin(),res.end());
        
        vector<vector<int>> ans;
        vector<int> help;
        
        for(int i=0;i<res.size();i++)
        {
            // cout<<res[i].first<<" "<<res[i].second<<endl;
            if(i==0||res[i][0]!=res[i-1][0])
            {
                if(i!=0)
                    ans.push_back(help);
                help.clear();
            }
            help.push_back(res[i][2]);
        }
        ans.push_back(help);
        return ans;
        
    }
};