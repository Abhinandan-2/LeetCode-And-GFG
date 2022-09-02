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
    vector<double> averageOfLevels(TreeNode* a) {
        
        vector<double> ans;
        int count =0 ;
        long long sum =0 ;
        double res;
        queue<TreeNode*> q;
        TreeNode *p;
        q.push(a);
        int i=1;
        
        while(!q.empty())
        {
            p = q.front();
            q.pop();
            sum += p->val;
            count++;
            if(p->left)
                q.push(p->left);
            if(p->right)
                q.push(p->right);
            i--;
            if(i==0)
            {
                res = sum/(double)count;
                ans.push_back(res);
                i = q.size();
                sum=0;
                count=0;
            }
        }
        
        return ans;
        
        
    }
};