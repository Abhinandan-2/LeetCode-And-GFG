class Solution {
public:
    int mergeStones(vector<int>& a, int k) {
        
        int n = a.size();
        
        if(n==1)
            return 0;
        if(k>n)
            return -1;
        if(k!=2&&(n%(k-1)!=1))
            return -1;
        
        vector<vector<int>> dp(n,vector<int> (n));
        vector<int> pre(n);
        int j;
        pre[0] = a[0];
        for(int i=1;i<n;i++)
            pre[i] = a[i]+pre[i-1];
        
        for(int len=k;len<=n;len++)
        {
            for(int i=0;i<=n-len;i++)
            {
                j = i+len-1;
                dp[i][j] = INT_MAX;
                for(int jump=i;jump<j;jump+=(k-1))
                    dp[i][j] = min(dp[i][j],dp[i][jump]+dp[jump+1][j]);
                if(k==2||(len%(k-1))==1)
                {
                    if(i==0)
                        dp[i][j] += pre[j];
                    else
                        dp[i][j]+= (pre[j]-pre[i-1]);
                }
            }
        }
        
        return dp[0][n-1];
        
        
        
    }
};