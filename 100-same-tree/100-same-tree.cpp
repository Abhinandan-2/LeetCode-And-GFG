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
    bool isSameTree(TreeNode* a, TreeNode* b) {
        TreeNode *p=a,*q=b;
        stack<TreeNode*> s1,s2;
        while(p||(!s1.empty()))
        {
            if(p)
            {
                s1.push(p);
                s2.push(q);
                p=p->left;
                if(!q)
                    return 0;
                q=q->left;
            }
            else
            {
                if(s2.empty())
                    return 0;
                q=s2.top();
                s2.pop();
                p=s1.top();
                s1.pop();
                if(p->val!=q->val)
                    return 0;
                q=q->right;
                p=p->right;
            }
        }
        p=a;
        q=b;
        while(!s1.empty())
            s1.pop();
        while(!s2.empty())
            s2.pop();
        while(q||(!s2.empty()))
        {
            if(q)
            {
                s2.push(q);
                s1.push(p);
                q=q->left;
                if(!p)
                    return 0;
                p=p->left;
            }
            else
            {
                if(s1.empty())
                    return 0;
                p=s1.top();
                s1.pop();
                q=s2.top();
                s2.pop();
                if(p->val!=q->val)
                    return 0;
                q=q->right;
                p=p->right;
            }
        }
        return 1;
        
    }
};