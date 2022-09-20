class Solution {
public:
    int findLength(vector<int>& a, vector<int>& b) {
        
        
        int n = a.size();
        int m = b.size();
        vector<vector<int>> v(n+1,vector<int> (m+1,0));
        int ans =0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i-1]==b[j-1])
                {
                    v[i][j] = v[i-1][j-1]+1;
                    ans = max(ans,v[i][j]);
                }
            }
        }
        return ans;
        
        
    }
};