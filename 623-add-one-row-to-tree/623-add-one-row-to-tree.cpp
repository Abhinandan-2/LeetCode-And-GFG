class Solution {
    void insertRow(TreeNode* a,int v,int d,int c){
        if(a){
            if(c==d){
                TreeNode *t1 = new TreeNode(v),*t2 = new TreeNode(v);
                t1->left = a->left;
                t2->right = a->right;
                a->left = t1;
                a->right = t2;
                return ;
            }
            if(c>d) return ;
            insertRow(a->left,v,d,c+1);
            insertRow(a->right,v,d,c+1);
        }
        return ;
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        TreeNode *t = new TreeNode(val);
        if(depth==1) {t->left = root;return t;}
        insertRow(root,val,depth-1,1);
        return root;
    }
};