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
    
    TreeNode* call(vector<int> &a,int s,int e)
    {
        if(s==e)
            return NULL;
        if(s+1==e)
        {
            TreeNode* t = new TreeNode(a[s]);
            return t;
        }
        int m = s+(e-s)/2;
        TreeNode* t = new TreeNode(a[m]);
        t->left = call(a,s,m);
        t->right = call(a,m+1,e);
        return t;
        
    }
    
    TreeNode* sortedArrayToBST(vector<int>& a) {
        
        int n = a.size();
        
        return call(a,0,n);
        
    }
};