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

    int call(TreeNode *a,int &ans){
        if(!a->left&&!a->right){
            ans = max(ans,a->val);
            return a->val;
        }
        else if(!a->left){
            int r = call(a->right,ans);
            ans = max({ans,a->val,r+a->val});
            return max(a->val,a->val+r);
        }
        else if(!a->right){
            int l = call(a->left,ans);
            ans = max({ans,a->val,l+a->val});
            return max(a->val,a->val+l);
        }
        else{
            int l = call(a->left,ans);
            int r = call(a->right,ans);
            ans = max({ans,l+a->val,r+a->val,l+r+a->val,a->val});
            return max({l+a->val,r+a->val,a->val});
        }
        return -1;
    }

    int maxPathSum(TreeNode* a) {
        int ans = INT_MIN;
        call(a,ans);
        return ans;
    }
};