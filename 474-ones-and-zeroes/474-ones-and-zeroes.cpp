class Solution {
public:
    
    
    int call(vector<string> &a,int zero,int one,int i,vector<vector<vector<int>>> &dp)
    {
        int n = a.size();
        
        if(i==n)
            return 0;
        if(zero==0&&one==0)
            return 0;
        if(dp[i][zero][one]!=-1)
            return dp[i][zero][one];
        
        int h=0,k=0;
        
        for(int j=0;j<a[i].size();j++)
        {
            if(a[i][j]=='1')
                h++;
            else
                k++;
        }
        int ans=0,f=-1,g=0;
        if(h<=one&&k<=zero)
        {
            f = call(a,zero-k,one-h,i+1,dp);
        }
        
        g = call(a,zero,one,i+1,dp);
        
        f++;
        ans = max(f,g);
        dp[i][zero][one] = ans;
        return ans;
        
        
        
    }
    
    int findMaxForm(vector<string>& a, int zero, int one) {
        
        int n = a.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (zero+1,vector<int>(one+1,-1)));
        
        int ans = call(a,zero,one,0,dp);
        
        return ans;
        
    }
};