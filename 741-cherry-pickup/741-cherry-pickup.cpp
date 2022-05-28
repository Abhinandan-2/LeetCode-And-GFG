class Solution {
    
    int backtrack(vector<vector<int>> &a,int r1,int c1,int c2, vector<vector<vector<int>>> &dp)
    {
        int n = a.size(),r2 = r1+c1-c2;
        if(r1>=n||c1>=n||c2>=n||r2>=n||a[r1][c1]==-1||a[r2][c2]==-1)
            return INT_MIN;
        if(dp[r1][c1][c2]!=-1)
            return dp[r1][c1][c2];
        if(r1==n-1&&c1==n-1)
            return a[r1][c1];
        int ans =0 ;
        ans += a[r1][c1];
        ans += a[r2][c2];
        if(r1==r2&&c2==c1)
        {
            if(a[r1][c1]==1)
                ans--;
        }
        
        int h , k ,p ,q;
        h = backtrack(a,r1+1,c1,c2,dp);
        k = backtrack(a,r1+1,c1,c2+1,dp);
        p = backtrack(a,r1,c1+1,c2,dp);
        q = backtrack(a,r1,c1+1,c2+1,dp);
        
        ans += max(h,max(k,max(p,q)));
        dp[r1][c1][c2] = ans;
        return ans;
    }
    
public:
    int cherryPickup(vector<vector<int>>& a) {
        
        int n = a.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (n,vector<int> (n,-1)));
        
        int ans = backtrack(a,0,0,0,dp);
        if(ans<0)
            return 0;
        return ans;
    }
};