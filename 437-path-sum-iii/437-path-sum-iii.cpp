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

#define ll long long

class Solution {
    
    void call(TreeNode *a,int t,unordered_map<ll,int> &m,ll &ans,ll sum)
    {
        if(a)
        {
            sum += a->val;
            if(m.count(sum-t))
                ans += m[sum-t];
            m[sum]++;
            call(a->left,t,m,ans,sum);
            call(a->right,t,m,ans,sum);
            m[sum]--;
        }
        return ;
    }
    
public:
    int pathSum(TreeNode* a, int t) {
        
        unordered_map<ll,int> m;
        m[0]++;
        ll ans =0,sum=0;
        call(a,t,m,ans,sum);
        
        return (int)ans;
    }
};