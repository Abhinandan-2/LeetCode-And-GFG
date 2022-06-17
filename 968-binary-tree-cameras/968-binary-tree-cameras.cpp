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
    
    pair<int,int> call(TreeNode *a,int &ans)
    {
        if(a)
        {
            pair<int,int> p ,q,r = {0,0}  , s = {0,1};
            p = call(a->left,ans);
            q = call(a->right,ans);
            if(p==r)
            {
                ans++;
                return {1,1};
            }
            if(p==s)
            {
                if(q==r)
                {
                    ans++;
                    return {1,1};
                }
                if(q==s)
                    return {0,0};
                return {0,1};
            }
            if(q==r)
            {
                ans++;
                return {1,1};
            }
            return {0,1};
        }
        return {0,1};
    }
    
    int minCameraCover(TreeNode* a) {
        
        int ans =0 ;
        pair<int,int> p = call(a,ans) , r= {0,0}, s  ={0,1};
        if(p==r)
            ans++;
        return ans;
        
    }
};