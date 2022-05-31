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
    
    pair<int,int> solve(TreeNode* root,int &ans)
    {
        if(root)
        {
            pair<int,int> leftStatus, rightStatus, notCameraButSafe, notCameraNotSafe;
            leftStatus = solve(root->left,ans);
            rightStatus = solve(root->right,ans);
            notCameraButSafe = {0,1};
            notCameraNotSafe = {0,0};
            if(leftStatus==notCameraNotSafe)
            {
                ans++;
                return {1,1};
            }
            else if(leftStatus==notCameraButSafe )
            {
                if(rightStatus==notCameraNotSafe)
                {
                    ans++;
                    return {1,1};
                }
                else if(rightStatus==notCameraButSafe )
                    return {0,0};
                else
                    return {0,1};
            }
            else
            {
                if(rightStatus==notCameraNotSafe)
                {
                    ans++;
                    return {1,1};
                }
                else if(rightStatus==notCameraButSafe )
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
        pair<int,int> status = solve(root,ans),notCameraNotSafe= {0,0};
        if(status==notCameraNotSafe)
            ans++;
        return ans;
        
    }
};