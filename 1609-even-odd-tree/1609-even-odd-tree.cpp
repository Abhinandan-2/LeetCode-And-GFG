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
    
    bool isEvenOdd(vector<int> &a,int k)
    {
        int n = a.size();
        if(n==0)
            return 1;
        int  h = a[0];
        if(k%2==0&&h%2!=0)
            return 0;
        if(k%2!=0&&h%2==0)
            return 0;
        
        for(int i=1;i<n;i++)
        {
            if(k%2!=0)
            {
                if(a[i]<=h)
                    return 0;
                if(a[i]%2==0)
                    return 0;
                h = a[i];
            }
            else
            {
                if(a[i]>=h)
                    return 0;
                if(a[i]%2!=0)
                    return 0;
                h = a[i];
            }
        }
        return 1;
    }
    
public:
    bool isEvenOddTree(TreeNode* a) {
        
        
        queue<TreeNode*> q;
        TreeNode* p;
        q.push(a);
        int i=1,j=0;
        vector<int> h;
        while(!q.empty())
        {
            p = q.front();
            q.pop();
            h.push_back(p->val);
            if(p->left)
                q.push(p->left);
            if(p->right)
                q.push(p->right);
            i--;
            if(i==0)
            {
                i = q.size();
                j++;
                if(!isEvenOdd(h,j))
                    return 0;
                h.clear();
            }
        }
        
        return 1;
        
    }
};