class Solution {
public:
    int call(int n,int tar,int k,vector<vector<int>> &dp){
        int mx = n*k ,mn= n;
        if(tar>mx||tar<mn) return 0;
        if(dp[n][tar]!=-1) return dp[n][tar];
        long long ans=0, mod = 1e9+7;
        if(n==1) {dp[n][tar] = 1; return 1;}
        for(int i=1;i<=k;i++) {ans += call(n-1,tar-i,k,dp); ans%=mod;}
        dp[n][tar] = (int)ans;
        return (int)ans;
    }
    int numRollsToTarget(int n, int k, int tar) {
        vector<vector<int>> dp(n+1,vector<int> (tar+1,-1));
        return call(n,tar,k,dp);
    }
};