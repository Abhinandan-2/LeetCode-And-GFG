class Solution {
public:
    
    int call(vector<int> &a,int i,int k,vector<vector<int>> &dp){
        
        int n = a.size(),ans=INT_MAX,res,mx=-1;
        if(dp[i][k]!=-1) return dp[i][k];
        if(k==1){
            ans = *max_element(a.begin()+i,a.end());
            dp[i][k] = ans;
            return ans;
        }
        for(int j=i;j<=n-k;j++){
            mx = max(mx,a[j]);
            res = call(a,j+1,k-1,dp);
            ans = min(ans,res+mx);
        }
        dp[i][k] = ans;
        return ans;
        
        
    }
    int minDifficulty(vector<int>& a, int k) {
        
        int n = a.size() ;
        if(n<k) return -1;
        vector<vector<int>> dp(n,vector<int> (k+1,-1));
        
        int ans = call(a,0,k,dp);
        return ans;
        
    }
};