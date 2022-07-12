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
class BSTIterator {
    
    stack<pair<TreeNode*,int>> s;
    
public:
    BSTIterator(TreeNode* root) {
        s.push({root,0});
    }
    
    int next() {
        
        pair<TreeNode*,int> p;
        while(s.top().second==0)
        {
            p = s.top();
            s.pop();
            s.push({p.first,1});
            if(p.first->left)
                s.push({p.first->left,0});
        }
        p = s.top();
        s.pop();
        int ans = p.first->val;
        if(p.first->right)
            s.push({p.first->right,0});
        return ans;
        
    }
    
    bool hasNext() {
        
        if(s.empty())
            return 0;
        return 1;
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */