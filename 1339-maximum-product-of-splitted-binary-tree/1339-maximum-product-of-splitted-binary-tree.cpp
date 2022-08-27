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
    
    void findSum(TreeNode* a,int &sum)
    {
        if(a)
        {
            sum += a->val;
            findSum(a->left,sum);
            findSum(a->right,sum);
        }
        return ;
    }
    
    int findAns(TreeNode* a,long long &ans,int sum)
    {
        if(a)
        {
            int x = findAns(a->left,ans,sum);
            int y = findAns(a->right,ans,sum);
            if(x!=0)
            {
                long long h = (long long)x*(sum-x);
                ans = max(ans,h);
            }
            if(y!=0)
            {
                long long h = (long long)y*(sum-y);
                ans = max(ans,h);
            }
            return x+y+a->val;
        }
        return 0;
    }
    
public:
    int maxProduct(TreeNode* a) {
        
        int sum =0 ;
        findSum(a,sum);
        
        long long mod =1e9+7, ans =0 ;
        
        findAns(a,ans,sum);
        ans %= mod;
        return ans;
        
    }
};