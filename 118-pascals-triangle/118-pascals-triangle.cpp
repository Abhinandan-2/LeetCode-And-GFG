class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>> ans;
        ans.push_back({1});
        if(n==1)
            return ans;
        ans.push_back({1,1});
        if(n==2)
            return ans;
        vector<int > v;
        for(int i=3;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(j==0||j==i-1)
                    v.push_back(1);
                else
                {
                    v.push_back(ans[i-2][j]+ans[i-2][j-1]);
                }
            }
            ans.push_back(v);
            v.clear();
        }
        return ans;
        
    }
};