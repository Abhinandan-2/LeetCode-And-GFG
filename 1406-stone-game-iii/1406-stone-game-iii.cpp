class Solution {
    
    int call(vector<int> &a,int i,int sum,vector<int> &dp)
    {
        int n = a.size();
        if(i>=n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ans = INT_MIN , g, f=0;
        for(int j=i;j<min(n,i+3);j++)
        {
            f += a[j];
            g = call(a,j+1,sum-f,dp);
            ans = max(ans,sum-g);
        }
        dp[i] = ans;
        return ans;
        
    }
    
public:
    string stoneGameIII(vector<int>& a) {
        
        int n = a.size();
        vector<int> dp(n,-1);
        
        int sum = accumulate(a.begin(),a.end(),0);
        
        int ans = call(a,0,sum,dp);
        int res = sum-ans;
        if(ans>res)
            return "Alice";
        if(res>ans)
            return "Bob";
        return "Tie";
        
        
        
    }
};