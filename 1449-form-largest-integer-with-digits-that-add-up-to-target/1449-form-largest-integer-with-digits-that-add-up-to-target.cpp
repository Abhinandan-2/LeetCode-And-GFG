class Solution {
public:
    string largestNumber(vector<int>& a, int t) {
        
        // reverse(a.begin(),a.end());
        
        int n = a.size();
        
        vector<vector<int>> dp(t+1,vector<int> (n+1,0));
        
        for(int i=1;i<=t;i++)
            dp[i][0] = -1;
        
        for(int i=1;i<=t;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i<a[j-1])
                    dp[i][j] = dp[i][j-1];
                else if(dp[i-a[j-1]][j]==-1)
                    dp[i][j] = dp[i][j-1];
                else
                    dp[i][j] = max(dp[i][j-1],dp[i-a[j-1]][j]+1);
            }
        }
        string ans;
        if(dp[t][n]==-1)
            return "0";
        int i = t , j = n,k;
        
        while(i>0&&j>0)
        {
            if(a[j-1]<=i)
            {
                if(dp[i-a[j-1]][j]!=-1&&dp[i-a[j-1]][j]+1==dp[i][j])
                {
                    ans.push_back(j+48);
                    i -= a[j-1];
                }
                else
                    j--;
            }
            else
                j--;
        }
        
        // reverse(ans.begin(),ans.end());
        return ans;
        
    }
};