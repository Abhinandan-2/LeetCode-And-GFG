/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void dis(TreeNode* a,int t,vector<int> &ans)
    {
        if(!a)
            return ;
        if(t==0)
        {
            ans.push_back(a->val);
            return ;
        }
        
        dis(a->left,t-1,ans);
        dis(a->right,t-1,ans);
        return ;
    }
    
    bool findTarget(TreeNode* a,TreeNode *t,vector<TreeNode*> &v)
    {
        if(a)
        {
            v.push_back(a);
            if(a==t)   
                return 1;
            
            if(findTarget(a->left,t,v))
                return 1;
            if(findTarget(a->right,t,v))
                return 1;
            v.pop_back();
            return 0;
        }
        return 0;
    }
    
    vector<int> distanceK(TreeNode* a, TreeNode* t, int k) {
        
        if(k==0)
            return {t->val};
        vector<TreeNode*> v;
        findTarget(a,t,v);
        vector<int> ans;
        dis(t,k,ans);
        int n = v.size(),j=1;
        // for(auto i:v)
        //     cout<<i->val<<" ";
        for(int i=n-2;i>=0;i--)
        {
            if(k-j==0)
            {
                ans.push_back(v[i]->val);
                break;
            }
            else
            {
                if(v[i]->left==v[i+1])
                    dis(v[i]->right,k-j-1,ans);
                else
                    dis(v[i]->left,k-j-1,ans);
            }
            j++;
        }
        return ans;
    }
};