class Solution {
public:
    
    int call(vector<vector<int>> &a,int i,int p,vector<vector<int>> &dp)
    {
        int n = dp.size();
        if(p==n-1)
            return 1;
        if(i>=41)
            return 0;
        if(dp[p][i]!=-1)
            return dp[p][i];
        
        long long ans =0 , mod = 1e9+7;
        int k;
        ans += call(a,i+1,p,dp);
        ans %= mod;
        
        for(int j=0;j<a[i].size();j++)
        {
            k = 1<<a[i][j];
            if((k&p)==0)
            {
                k = k|p;
                ans += call(a,i+1,k,dp);
                ans %= mod;
            }
        }
        
        dp[p][i]=(int)ans;
        return dp[p][i];
        
        
    }
    
    int numberWays(vector<vector<int>>& z) {
        
        vector<vector<int>> a(41);
        int n = z.size();
        for(int i=0;i<z.size();i++)
        {
            for(int j=0;j<z[i].size();j++)
                a[z[i][j]].push_back(i);
        }
        
        vector<vector<int>> dp(1<<n,vector<int> (41,-1));
        
        int ans = call(a,1,0,dp);
        return ans;
        
        
        
    }
};