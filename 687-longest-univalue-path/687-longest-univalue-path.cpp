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
    
    pair<int,int> solve(TreeNode* a,int &ans)
    {
        if(a)
        {
            int res;
            pair<int,int> l,r;
            l = solve(a->left,ans);
            r = solve(a->right,ans);
            if(l.first==a->val&&r.first==a->val)
            {
                ans = max(ans,l.second+r.second);
                res = max(l.second,r.second)+1;
            }
            else if(l.first==a->val)
            {
                ans = max(ans,l.second);
                res = l.second+1;
            }
            else if(r.first==a->val)
            {
                ans = max(ans,r.second);
                res = r.second+1;
            }
            else
            {
                res = 1;
            }
            return {a->val,res};
        }
        return {-1001,1};
    }
    
public:
    int longestUnivaluePath(TreeNode* a) {
        
        int ans = 0 ;
        solve(a,ans);
        return ans;
        
    }
};