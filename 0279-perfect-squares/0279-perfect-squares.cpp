class Solution {
public:
    
    int dp(int n,vector<int> &v)
    {
        if(v[n]!=-1)
            return v[n];
        int h = sqrt(n);
        h *= h;
        if(h==n)
        {
            v[n] = 1;
            return v[n];
        }
        int ans = INT_MAX;
        for(int i=1;i<=sqrt(n);i++)
        {
            ans = min(ans,dp(n-i*i,v));
        }
        
        v[n] = ans+1;
        return v[n];
        
        
    }
    
    
    int numSquares(int n) {
        
        vector<int> v(n+1,-1);
        int ans = dp(n,v);
        return ans;
        
        
    }
};