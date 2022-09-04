class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* a) {
        vector<vector<int>> res,ans;
        vector<int> help;
        queue<pair<TreeNode*,int>> q;
        pair<TreeNode*,int> p;
        q.push({a,0});
        int level = 0,i=1;
        while(!q.empty()){
            p = q.front();q.pop();
            res.push_back({p.second,level,p.first->val});
            if(p.first->left) q.push({p.first->left,p.second-1});
            if(p.first->right) q.push({p.first->right,p.second+1});
            if(--i==0){ i = q.size(); level++;}
        }
        sort(res.begin(),res.end());
        for(int i=0;i<res.size();i++){
            if(i==0||res[i][0]!=res[i-1][0]){
                if(i!=0) ans.push_back(help);
                help.clear();
            }
            help.push_back(res[i][2]);
        }
        ans.push_back(help);
        return ans;
    }
};