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
    
    TreeNode* makeTree(vector<int> &pre,vector<int> &in,int &i,int st,int en)
    {
        TreeNode *t;
        if(st>en)
            return NULL;
        if(st==en)
        {
            t = new TreeNode(pre[i]);
            i++;
            return t;
        }
        
        int f =-1;
        for(int j=st;j<=en;j++)
        {
            if(in[j]==pre[i])
            {
                f = j;
                break;
            }
        }
        
        t = new TreeNode(in[f]);
        i++;
        t->left = makeTree(pre,in,i,st,f-1);
        t->right = makeTree(pre,in,i,f+1,en);
        return t;
    }
    
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        
        int n = in.size(),i=0;
        TreeNode *ans = makeTree(pre,in,i,0,n-1);
        return ans;
        
    }
};