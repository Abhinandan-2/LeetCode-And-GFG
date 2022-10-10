class Solution {
public:
    int longestArithSeqLength(vector<int>& a) {
        int n = a.size(),ans=0,diff,count;
        vector<vector<int>> dp(n,vector<int> (1007,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                diff = a[j]-a[i]+503;
                count = dp[j][diff]+1;
                if(dp[i][diff]<count) dp[i][diff] = count;
                ans = max(ans,count);
            }
        }
        return ans+1;
    }
};