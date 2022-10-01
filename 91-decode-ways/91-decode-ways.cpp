class Solution {
public:
    int call(string &a,int i,vector<int> &dp){
        int n = a.size(),ans1=0,ans2=0;
        if(i==n) return 1;
        if(i>n) return 0;
        if(dp[i]!=-1) return dp[i];
        if(a[i]=='0') {dp[i] = 0;return 0;}
        ans1 = call(a,i+1,dp);
        if(a[i]=='1') ans2 = call(a,i+2,dp);
        if(a[i]=='2'&&i<n-1&&a[i+1]>='0'&&a[i+1]<='6') ans2 = call(a,i+2,dp);
        dp[i] = ans1+ans2;
        return dp[i];
    }
    int numDecodings(string a) {
        int n = a.size();
        vector<int> dp(n,-1);
        return call(a,0,dp);
    }
};