class Solution {
    
    int call(int len,int num,vector<vector<int>> &adj,vector<vector<int>> &dp)
    {
        
        if(len==1)
            return 1;
            
        if(dp[len][num]!=-1)
            return dp[len][num];
        
        long long ans =0 , mod = 1e9+7;
        
        for(int i=0;i<adj[num].size();i++)
        {
            ans += call(len-1,adj[num][i],adj,dp);
            ans %=  mod;
        }
        
        dp[len][num] = (int)ans;
        
        return (int)ans;
        
    }
    
public:
    int knightDialer(int len) {
        
        vector<vector<int>> adj(10);
        adj[0].push_back(4);
        adj[0].push_back(6);
        adj[1].push_back(8);
        adj[1].push_back(6);
        adj[2].push_back(7);
        adj[2].push_back(9);
        adj[3].push_back(4);
        adj[3].push_back(8);
        adj[4].push_back(3);
        adj[4].push_back(9);
        adj[4].push_back(0);
        adj[6].push_back(1);
        adj[6].push_back(7);
        adj[6].push_back(0);
        adj[7].push_back(2);
        adj[7].push_back(6);
        adj[8].push_back(1);
        adj[8].push_back(3);
        adj[9].push_back(4);
        adj[9].push_back(2);
        
        vector<vector<int>> dp(len+1,vector<int> (10,-1));
        
        long long ans =0 , mod =1e9+7;
        
        for(int i=0;i<10;i++)
        {
            ans += call(len,i,adj,dp);
            ans %= mod;
        }
        
        return (int)ans;
        
        
    }
};