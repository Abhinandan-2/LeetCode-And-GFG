class Solution {
    
    int call(vector<int> &a,int sum,int i,int m,vector<vector<int>> &dp)
    {
        
        int n = a.size();
        int h = n-i;
        // cout<<i<<" "<<m<<" "<<sum<<endl;
        if(dp[i][m]!=-1)
            return dp[i][m];
        if(h<=m)
        {
            dp[i][m] = sum;
            return dp[i][m];
        }
        int ans = 0 , f=0, g=m/2,res;
        for(int j=i;j<i+m;j++)
        {
            f += a[j];
            h = call(a,sum-f,j+1,2*max(j-i+1,g),dp);
            res = f+(sum-f-h);
            ans=max(ans,res);
        }
        dp[i][m] = ans;
        return ans;
    }
    
public:
    int stoneGameII(vector<int>& a) {
        
        int n = a.size();
        vector<vector<int>> dp(n,vector<int> (n+7,-1));
        
        int sum = accumulate(a.begin(),a.end(),0);
        
        int ans = call(a,sum,0,2,dp);
        
        // for(auto i:dp)
        // {
        //     for(auto j:i)
        //         cout<<j<<" ";
        //     cout<<endl;
        // }
        
        return ans;
        
        
        
    }
};