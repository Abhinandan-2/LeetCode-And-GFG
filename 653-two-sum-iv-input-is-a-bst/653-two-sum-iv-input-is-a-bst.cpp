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
    
    void inc(TreeNode **a,stack<TreeNode*> &s){
        if((*a)->right){
            (*a) = (*a)->right;
            while((*a)->left){
                s.push(*a);
                (*a)=(*a)->left;
            }
        }
        else{
            (*a)= s.top();
            s.pop();
        }
        return ;
    }
    void dec(TreeNode **a,stack<TreeNode*> &s){
        if((*a)->left){
            (*a)=(*a)->left;
            while((*a)->right){
                s.push(*a);
                (*a)=(*a)->right;
            }
        }
        else{
            (*a)=s.top();
            s.pop();
        }
        return ;
    }
    
public:
    bool findTarget(TreeNode* a, int k) {
        stack<TreeNode*> ps ,qs;
        TreeNode *p = a, *q = a;
        while(p->left){
            ps.push(p);
            p=p->left;
        }
        while(q->right){
            qs.push(q);
            q=q->right;
        }
        while(p!=q){
            if(p->val+q->val==k) return true;
            if(p->val+q->val>k) dec(&q,qs);
            else inc(&p,ps);
        }
        return false; 
    }
};