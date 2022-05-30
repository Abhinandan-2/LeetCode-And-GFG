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
    
    void getPermutations(int n,vector<int> &vis,vector<int> &help,vector<vector<int>> &ans)
    {
        if(help.size()==n)
        {
            ans.push_back(help);
            return ;
        }
        
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==-1)
            {
                help.push_back(i);
                vis[i]=1;
                getPermutations(n,vis,help,ans);
                vis[i]=-1;
                help.pop_back();
            }
        }
        return ;
    }
    
    TreeNode* insert(TreeNode* a,int vl)
    {
        if(a==NULL)
        {
            TreeNode *t = new TreeNode(vl);
            return t;
        }
        
        if(vl<a->val)
        {
            a->left = insert(a->left,vl);
            return a;
        }
        a->right = insert(a->right,vl);
        return a;
    }
    
    TreeNode* makeTree(vector<int> &a)
    {
        int n = a.size();
        TreeNode *root = new TreeNode(a[0]);
        for(int i=1;i<n;i++)
            root = insert(root,a[i]);
        return root;
    }
    
    void preorder(TreeNode* a,vector<int> &v)
    {
        if(a)
        {
            v.push_back(a->val);
            preorder(a->left,v);
            preorder(a->right,v);
        }
        return ;
    }
    
    
public:
    vector<TreeNode*> generateTrees(int n) {
                
        vector<vector<int>> all;
        vector<int> vis(n+1,-1),help;
        getPermutations(n,vis,help,all);
        
        vector<TreeNode*> ans; 
        TreeNode *root;
        map<vector<int>,int> mp;
        
        for(int i=0;i<all.size();i++)
        {
            help.clear();
            root = makeTree(all[i]);
            preorder(root,help);
            if(!mp.count(help))
            {
                mp[help]=1;
                ans.push_back(root);
            }       
        }
        return ans;
        
    }
};