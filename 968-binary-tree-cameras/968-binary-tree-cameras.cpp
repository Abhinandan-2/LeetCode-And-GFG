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
    
    pair<int,int> solve(TreeNode* a,int &ans)
    {
        if(a)
        {
            pair<int,int> p, q, notCameraButSafe, notCameraNotSafe;
            p = solve(a->left,ans);
            q = solve(a->right,ans);
            notCameraButSafe = {0,1};
            notCameraNotSafe = {0,0};
            if(p==notCameraNotSafe)
            {
                ans++;
                return {1,1};
            }
            else if(p==notCameraButSafe )
            {
                if(q==notCameraNotSafe)
                {
                    ans++;
                    return {1,1};
                }
                else if(q==notCameraButSafe )
                    return {0,0};
                else
                    return {0,1};
            }
            else
            {
                if(q==notCameraNotSafe)
                {
                    ans++;
                    return {1,1};
                }
                else if(q==notCameraButSafe )
                    return {0,1};
                else
                    return {0,1};
            }
        }
        return {0,1};
    }
    
public:
    int minCameraCover(TreeNode* root) {
        
        int ans =0;
        pair<int,int> p = solve(root,ans),notCameraNotSafe= {0,0};
        if(p==notCameraNotSafe)
            ans++;
        return ans;
        
    }
};