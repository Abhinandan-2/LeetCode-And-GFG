class Solution {
    void preordered(TreeNode *a,string &ans){
        ans += to_string(a->val);
        if(a->right){
            ans+="(";
            if(a->left) preordered(a->left,ans);
            ans+=")(";
            preordered(a->right,ans);
            ans+=")";
            return ;
        }
        if(a->left) {
            ans+="(";
            preordered(a->left,ans);
            ans+=")";
        }
        return ;  
    }   
public:
    string tree2str(TreeNode* a) {
        string ans;
        preordered(a,ans);
        return ans;  
    }
};