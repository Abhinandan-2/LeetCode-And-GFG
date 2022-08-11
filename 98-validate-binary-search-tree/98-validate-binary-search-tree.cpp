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
    
    pair<bool,pair<int,int>> call(TreeNode* a)
    {
        if(!a->left&&!a->right)
        {
            return {true,{a->val,a->val}};
        }
        
        pair<bool,pair<int,int>> p,q;
        int mn,mx;
        
        if(!a->left)
        {
            p = call(a->right);
            if(p.first==false)
                return {false,{0,0}};
            mx = p.second.second;
            mn = p.second.first;
            if(mn<=a->val)
                return {false,{0,0}};
            mn = min(mn,a->val);
            return {true,{mn,mx}};
        }
        if(!a->right)
        {
            p = call(a->left);
            if(p.first==false)
                return {false,{0,0}};
            mx = p.second.second;
            mn = p.second.first;
            if(mx>=a->val)
                return {false,{0,0}};
            mx = max(mx,a->val);
            return {true,{mn,mx}};
        }
        p = call(a->left);
        q = call(a->right);
        if(p.first==false||q.first==false)
            return {false,{0,0}};
        if(p.second.second>=a->val)
            return {false,{0,0}};
        if(q.second.first<=a->val)
            return {false,{0,0}};
        mn = min(a->val,min(p.second.first,q.second.first));
        mx = max(a->val,max(p.second.second,q.second.second));
        
        return {true,{mn,mx}};
            
    }
    
    bool isValidBST(TreeNode* a) {
        
        
        if(!a)
            return 1;
        
        pair<bool,pair<int,int>> p = call(a);
        return p.first;
        
    }
};