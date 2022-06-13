class Solution {
    
    int call(vector<int> &a,int s,int e,vector<vector<int>> &dp)
    {
        int n = a.size();
        if(s==e)
            return a[s];
        if(s+1==e)
            return max(a[s],a[e]);
        if(dp[s][e]!=-1)
            return dp[s][e];
        int h = call(a,s+2,e,dp);
        int k = call(a,s+1,e-1,dp);
        int l = call(a,s,e-2,dp);
        int ans = max(a[s]+min(h,k),a[e]+min(k,l));
        dp[s][e] = ans;
        return ans;
    }
    
public:
    bool stoneGame(vector<int>& a) {
        
        int n = a.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        int sum = accumulate(a.begin(),a.end(),0);
        int ans = call(a,0,n-1,dp);
        int res = sum-ans;
        if(ans>res)
            return 1;
        return 0;
        
        
    }
};