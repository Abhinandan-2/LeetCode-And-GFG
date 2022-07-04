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
    
    bool pali(unordered_map<int,int> &a)
    {
        int o=0;
        for(auto i:a)
        {
            if(i.second%2!=0)
                o++;
        }
        if(o>1)
            return 0;
        return 1;
    }
    
    void call(TreeNode *a,unordered_map<int,int> &m,int &ans)
    {
        if(a)
        {
            m[a->val]++;
            
            if(!a->left&&!a->right)
            {
                if(pali(m))
                    ans++;
                m[a->val]--;
                return ;
            }
            
            call(a->left,m,ans);
            call(a->right,m,ans);
            m[a->val]--;
            return ;
        }
        
        return ;
    }
    
    int pseudoPalindromicPaths (TreeNode* a) {
        
        unordered_map<int,int> m;
        
        int ans =0;
        
        call(a,m,ans);
        
        return ans;
        
        
        
    }
};