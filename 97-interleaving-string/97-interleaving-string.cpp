class Solution {
public:
    
    bool call(int i,int k,vector<vector<int>> &dp,string &a,string &b,string &c)
    {
       
        int n = a.size() , m = b.size() , len = c.size();
        
        if(i==n&&k==len)
            return 1;
        
        int j = k-i;
        // cout<<i<<" "<<j<<" "<<k<<endl;
        if(dp[k][i]!=-1)
            return dp[k][i];
        
        if(i==n)
        {
            if(b[j]==c[k])
            {
                if(call(i,k+1,dp,a,b,c))
                {
                    dp[k][i] = 1;
                    return 1;
                }
            }
            dp[k][i] = 0;
            return 0;
        }
        if(j==m)
        {
            if(a[i]==c[k])
            {
                if(call(i+1,k+1,dp,a,b,c))
                {
                    dp[k][i] = 1;
                    return 1;
                }
            }
            dp[k][i] = 0;
            return 0;
        }
        if(a[i]==c[k]&&b[j]==c[k])
        {
            bool first = call(i+1,k+1,dp,a,b,c);
            if(first)
            {
                dp[k][i] = 1;
                return 1;
            }
            if(call(i,k+1,dp,a,b,c))
            {
                dp[k][i] = 1;
                return 1;
            }
            dp[k][i] = 0;
            return 0;
        }
        else if(a[i]==c[k])
        {
            if(call(i+1,k+1,dp,a,b,c))
            {
                dp[k][i] = 1;
                return 1;
            }
            dp[k][i] = 0;
            return 0;
        }
        else if(b[j]==c[k])
        {
            // cout<<54;
            if(call(i,k+1,dp,a,b,c))
            {
                dp[k][i] = 1;
                return 1;
            }
            dp[k][i] =0 ;
            return 0;
        }
        else
            dp[k][i] = 0;
        return 0;
        
        
    }
    
    bool isInterleave(string a, string b, string c) {
        
        int n = a.size() , m = b.size() , len = c.size();
        
        if(n+m!=len)
            return 0;
        
        vector<vector<int>> dp(len,vector<int>(n+1,-1));
        
        bool ans = call(0,0,dp,a,b,c);
        
        return ans;
        
        
        
    }
};