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
    
    pair<int,bool> call(TreeNode* a)
    {
        if(a){
            pair<int,bool> x = call(a->left);
            
            if(x.second==0)
                return {-1,0};
            
            pair<int,bool> y = call(a->right);
            
            if(y.second==0)
                return {-1,0};
            
            if(abs(x.first-y.first)>1)
                return {-1,0};
            
            if(y.first>x.first)
            {
                return {y.first+1,1};
            }
            
            return {x.first+1,1};
            
        }
        return {0,1};
    }
    
    
    bool isBalanced(TreeNode* a) {
        
        pair<int,bool> p = call(a);
        
        return p.second;
        
        
    }
};