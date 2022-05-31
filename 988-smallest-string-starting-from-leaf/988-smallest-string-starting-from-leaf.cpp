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
    
    string small(string &a,string &b)
    {
        int i =0 ,j =0 , n = a.size() , m = b.size();
        if(a==b)
            return a;
        while(i<n&&j<m)
        {
            if(a[i]<b[j])
                return a;
            if(a[i]>b[j])
                return b;
            i++;
            j++;
        }
        if(i==n)
            return a;
        return b;
        
    }
    
    void call(TreeNode* a,string &help,string &ans)
    {
        if(a)
        {
            if(!a->left&&!a->right)
            {
                help.push_back(a->val+97);
                reverse(help.begin(),help.end());
                if(ans.size()==0)
                    ans = help;
                else
                    ans = small(ans,help);
                reverse(help.begin(),help.end());
                help.pop_back();
                return ;
            }
            help.push_back(a->val+97);
            call(a->left,help,ans);
            call(a->right,help,ans);
            help.pop_back();
        }
        return ;
    }
    
public:
    string smallestFromLeaf(TreeNode* root) {
        
        string ans,help;
        call(root,help,ans);
        return ans;   
    }
};