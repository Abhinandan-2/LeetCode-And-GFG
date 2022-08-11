class Solution {
public:
    
    vector<vector<int>> findSameChar(string &b,string &a)
    {
        int n = a.size(), m=b.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                if(a[i-1]==b[j-1])
                    dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
            }
        }
        
        return dp;
    }
    
    int minInsertions(string a) {
        
        int n = a.size();
        if(n==1)
            return 0;
        string b= a;
        reverse(b.begin(),b.end());
        vector<vector<int>> dp = findSameChar(b,a);
        int last = dp[n][n];
        int ans = n-last;
        return ans;
       
    }
};