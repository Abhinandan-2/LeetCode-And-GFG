class Solution {
    
    int dfs(int n,int m,int t,int r,int c,vector<vector<vector<int>>> &dp,int x[],int y[])
    {
        if(r<0||r>=n||c<0||c>=m)
            return 1;
        if(t==0)
            return 0;
        if(dp[r][c][t]!=-1)
            return dp[r][c][t];
        
        long long ans =0 , mod = 1e9+7;
        int i,j;
        
        for(int k=0;k<4;k++)
        {
            i = r+x[k];
            j = c+y[k];
            ans += dfs(n,m,t-1,i,j,dp,x,y);
            ans %= mod;
        }
        
        dp[r][c][t] = ans;
        return (int)ans;
    }
    
    
public:
    int findPaths(int n, int m, int t, int r, int c) {
        
        
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(t+1,-1)));
        int x[] = {0,0,1,-1};
        int y[] = {1,-1,0,0};
        
        
        int ans = dfs(n,m,t,r,c,dp,x,y);
        
        return ans;
        
        
    }
};