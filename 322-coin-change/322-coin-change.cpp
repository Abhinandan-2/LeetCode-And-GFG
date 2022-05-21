class Solution {
public:
    int coinChange(vector<int>& a, int k) {
        
        int n = a.size();
        sort(a.begin(),a.end());
        
        vector<vector<int>> dp(k+1,vector<int> (n+1,INT_MAX));
        
        for(int i=0;i<=n;i++)
        {
            dp[0][i]  = 0;
        }
        
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[j-1]>i)
                {
                    dp[i][j] = dp[i][j-1];
                }
                else
                {
                    if(dp[i-a[j-1]][j]==INT_MAX)
                        dp[i][j] = dp[i][j-1];
                    else
                    dp[i][j] = min(dp[i][j-1],dp[i-a[j-1]][j]+1);
                }
            }
        }
        if(dp[k][n]==INT_MAX)
            return -1;
        return dp[k][n];
        
        
        
    }
};