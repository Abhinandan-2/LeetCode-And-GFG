class Solution {
    int call(vector<int> &a,int x,int k,vector<vector<int>> &dp){
        int n = a.size();
        if(k==0||x==n) return 0;
        if(dp[x][k]!=-1) return dp[x][k];
        int ans =0 ,res;
        for(int i=x;i<n;i++){
            if(a[i]>a[x]){
            res = call(a,i+1,k-1,dp);
            res += (a[i]-a[x]);
            ans = max(ans,res);
            }
        }
        res = call(a,x+1,k,dp);
        ans = max(ans,res);
        dp[x][k] = ans;
        return ans;
    }
public:
    int maxProfit(int k, vector<int>& a) {
        vector<vector<int>> dp(a.size(),vector<int> (k+1,-1));
        return call(a,0,k,dp);
    }
};