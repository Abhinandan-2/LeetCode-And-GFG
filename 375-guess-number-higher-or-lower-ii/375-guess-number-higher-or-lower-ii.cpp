class Solution {
    
    int call(int s,int e,vector<vector<int>> &dp)
    {
        if(s>e)
            return 0;
        if(s==e)
            return 0;
        if(s+1==e)
            return s;
        if(dp[s][e]!=-1)
            return dp[s][e];
        
        int ans =INT_MAX ,f1,f2;
        for(int i=s;i<=e;i++)
        {
            f1 = call(s,i-1,dp);
            f2 = call(i+1,e,dp);
            ans = min(ans,i+max(f1,f2));
        }
        dp[s][e] = ans;
        return ans;
    }
    
public:
    int getMoneyAmount(int n) {
        
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        int ans = call(1,n,dp);
        return ans;
        
    }
};