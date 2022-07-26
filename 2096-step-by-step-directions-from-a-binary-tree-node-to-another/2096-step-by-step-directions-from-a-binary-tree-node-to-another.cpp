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
    
    bool pathFinder(TreeNode* a,int t,vector<int> &v)
    {
        if(!a)
            return 0;
        if(a->val==t)
            return 1;
        v.push_back(0);
        if(pathFinder(a->left,t,v))
            return 1;
        v.pop_back();
        v.push_back(1);
        if(pathFinder(a->right,t,v))
            return 1;
        v.pop_back();
        return 0;
    }
    
public:
    string getDirections(TreeNode* r, int st, int ed) {
        
        vector<int> a,b;
        pathFinder(r,st,a);
        pathFinder(r,ed,b);
        
        int i=0 ,j =0 , n = a.size() , m = b.size();
        
        // for(auto i:a)
        //     cout<<i<<" ";
        // cout<<endl;
        // for(auto i:b)
        //     cout<<i<<" ";
        // cout<<endl;
        
        while(i<n&&j<m)
        {
            if(a[i]==b[j])
            {
                i++;
                j++;
            }
            else
                break;
        }
        // cout<<i<<" "<<j<<endl;
        string ans;
        
        while(i<n)
        {
            ans.push_back('U');
            i++;
        }
        
        while(j<m)
        {
            if(b[j]==0)
                ans.push_back('L');
            else
                ans.push_back('R');
            j++;
        }
        return ans;
        
    }
};