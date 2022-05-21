class Solution {
public:
    
    int call(vector<int> &a,int t,vector<vector<int>> &dp)
    {
        int n = a.size();
        
        if(t==0)
            return 0;
        call(a,t-1,dp);
       
        for(int i=0;i<n;i++)
        {
            if(t<a[i])
            {
                if(i==0)
                    dp[t][i] = INT_MAX;
                else
                    dp[t][i]  = dp[t][i-1];
            }
            else
            {
                if(dp[t-a[i]][i]==INT_MAX)
                {
                    if(i==0)
                        dp[t][i] = INT_MAX;
                    else
                        dp[t][i] = dp[t][i-1];
                }
                else
                {
                    if(i==0)
                        dp[t][i] = dp[t-a[i]][i]+1;
                    else
                        dp[t][i]  = min(dp[t][i-1],dp[t-a[i]][i]+1);
                }
            }
        }
        return dp[t][n-1];
        
        
    }
    
    
    int coinChange(vector<int>& a, int t) {
        
        int n = a.size();
        
        vector<vector<int>> dp(t+1,vector<int> (n,-1));
        for(int i=0;i<n;i++)
            dp[0][i] = 0;
        int ans = call(a,t,dp);
        if(ans==INT_MAX)
            return -1;
        return ans;   
    }
};