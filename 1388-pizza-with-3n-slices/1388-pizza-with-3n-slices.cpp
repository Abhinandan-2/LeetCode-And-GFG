class Solution {
public:
    
    int call(vector<int> &a,int i,int k,int b,vector<vector<vector<int>>> &dp)
    {
        int n = a.size();
        if(k==0)
            return 0;
        if(i>=n)
            return 0;
        if(b==1&&i==n-1)
            return 0;
        if(dp[i][k][b]!=-1)
            return dp[i][k][b];
        
        int ans =0,g,f ;
        
        f = call(a,i+2,k-1,b,dp);
        g = call(a,i+1,k,b,dp);
        
        ans = max(f+a[i],g);
        dp[i][k][b] = ans;
        return ans;
        
    }
    
    int maxSizeSlices(vector<int>& a) {
        
        int n = a.size() ;
        int k = n/3;
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (k+1,vector<int> (2,-1)));
        
        int ans,f,g;
        f = call(a,2,k-1,1,dp);
        g = call(a,1,k,0,dp);
        
        ans = max(f+a[0],g);
        return ans;   
    }
};