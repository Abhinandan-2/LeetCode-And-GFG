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
    
    void call(TreeNode* a,unordered_map<int,int> &m,vector<TreeNode*> &ans)
    {
        if(a)
        {
            call(a->left,m,ans);
            call(a->right,m,ans);
            if(m.count(a->val))
            {
                if(a->left&&!m.count(a->left->val))
                    ans.push_back(a->left);
                a->left = NULL;
                if(a->right&&!m.count(a->right->val))
                    ans.push_back(a->right);
                a->right=NULL;
            }
            else
            {
                if(a->left&&m.count(a->left->val))
                    a->left= NULL;
                if(a->right&&m.count(a->right->val))
                    a->right=NULL;
            }
        }
        return ;
    }
    
public:
    vector<TreeNode*> delNodes(TreeNode* r, vector<int>& b) {
        
        unordered_map<int,int> m;
        for(auto i:b)
            m[i]++;
        
        vector<TreeNode*> ans;
        
        call(r,m,ans);
        if(m.count(r->val))
        {
            if(r->left&&!m.count(r->left->val))
                ans.push_back(r->left);
            r->left = NULL;
            if(r->right&&!m.count(r->right->val))
                ans.push_back(r->right);
            r->right=NULL;
        }
        else
        {
            if(r->left&&m.count(r->left->val))
                r->left= NULL;
            if(r->right&&m.count(r->right->val))
                r->right=NULL;
            ans.push_back(r);
        }
        return ans;
        
    }
};