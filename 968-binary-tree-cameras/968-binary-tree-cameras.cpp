class Solution {
    
    pair<int,int> solve(TreeNode* root,int &ans){
        
        if(root!=NULL){
            
            pair<int,int> leftStatus, rightStatus, notCameraButSafe, notCameraNotSafe;
            leftStatus = solve(root->left,ans);
            rightStatus = solve(root->right,ans);
            notCameraButSafe = {0,1};
            notCameraNotSafe = {0,0};
            if(leftStatus==notCameraNotSafe){
                ans++;
                return {1,1};        // If the left has no camera and is not covered, this node must have a camera to cover the left child.
            }
            else if(leftStatus==notCameraButSafe ){
                if(rightStatus==notCameraNotSafe){
                    ans++;
                    return {1,1};         // If the right has no camera and it is not covered, this node must have a camera to cover right child.
                }
                else if(rightStatus==notCameraButSafe )
                    return {0,0};            // If both have no camera and both are covered then this node is not covered and does not have camera.
                else
                    return {0,1};   // If the right has a camera then this node is covered and does not have camera.
            }
            else{
                if(rightStatus==notCameraNotSafe){
                    ans++;
                    return {1,1};  // If the right has no camera and it is not covered, this node must have a camera to cover right child.
                }
                else if(rightStatus==notCameraButSafe )
                    return {0,1};    // If the left has a camera then this node is covered and does not have camera.
                else
                    return {0,1};  // If both have a camera then this node is covered and does not have camera.
            }
        }
        return {0,1};   // If NULL then it is covered and does not have camera.
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