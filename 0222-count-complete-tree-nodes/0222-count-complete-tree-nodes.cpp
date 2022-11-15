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
    
    int height(TreeNode *r)
    {
        if(r)
        {
            int x = height(r->left);
            int y = height(r->right);
            if(x>y)
                return x+1;
            return y+1;
        }
        return 0;
    }
    
    bool is(TreeNode *a,int m,int s)
    {
        vector<int> v;
        while(m)
        {
           v.push_back(m%2);
            m/=2;
        }
        while(v.size()<s)
            v.push_back(0);
        int n = v.size();
        for(int i=n-1;i>=0;i--)
        {
            if(v[i]==1)
            {
                if(!a->right)
                    return 0;
                a=a->right;
            }
            else
            {
                if(!a->left)
                    return 0;
                a=a->left;
            }
        }
        return 1;
    }
                    
    
    int countNodes(TreeNode* r) {
        
        int ans =0 ;
        if(!r)
            return 0;
        if(!r->left&&!r->right)
            return 1;
        
        int h = height(r);
        
        h--;
        int p = h;
        ans += pow(2,h)-1;
        int l =0 , m ,k=-1;
        h = pow(2,h)-1;
        
        while(l<=h)
        {
            m = l+(h-l)/2;
            if(is(r,m,p))
            {
                k = m;
                l = m+1;
            }
            else
                h = m-1;
        }
        
        ans+= k+1;
        return ans;
        
        
    }
};