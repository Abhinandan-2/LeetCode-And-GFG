class Solution {
    
    int calNeighbours(vector<int> &house)
    {
        int ans =0,precolor = -1 ;
        
        for(int i=0;i<house.size();i++)
        {
            if(house[i]!=0)
            { 
                if(precolor!=house[i])
                {
                    precolor = house[i];
                    ans++;
                }
            }
        }
        
        return ans;
        
    }
    
    
    int calMinCost(vector<int> &house,vector<vector<int>> &cost,int m,int n,int target,int precolor,vector<vector<vector<int>>> &dp,int pos)
    {
        
        int ans , res = INT_MAX, curCost;
        if(pos==m)
        {
            if(target==0)
                return 0;
            return INT_MAX;
        }
        
        if(dp[pos][target][precolor]!=-1)
            return dp[pos][target][precolor];
        
           
        if(target==0)
        {
            if(house[pos]==0)
            {
                ans = calMinCost(house,cost,m,n,target,precolor,dp,pos+1);
                if(ans!=INT_MAX)
                    dp[pos][target][precolor] = ans+cost[pos][precolor-1];
                else
                    dp[pos][target][precolor] = INT_MAX;
                return dp[pos][target][precolor];
            }
            if(house[pos]==precolor)
            {
                ans = calMinCost(house,cost,m,n,target,precolor,dp,pos+1);
                dp[pos][target][precolor] = ans;
                return ans;
            }
            dp[pos][target][precolor] = INT_MAX;
            return INT_MAX;
        }
        
        
        if(house[pos]==0)
        {
            for(int i=1;i<=n;i++)
            {
                curCost = cost[pos][i-1];
                if(precolor==i)
                {
                    ans = calMinCost(house,cost,m,n,target,precolor,dp,pos+1);
                }
                else
                {
                    ans = calMinCost(house,cost,m,n,target-1,i,dp,pos+1);
                }
                if(ans!=INT_MAX)
                    res = min(res,ans+curCost);
            }
            dp[pos][target][precolor] = res;
            return res;
        }
        
        if(house[pos]==precolor)
            ans = calMinCost(house,cost,m,n,target,precolor,dp,pos+1);
        else
            ans = calMinCost(house,cost,m,n,target-1,house[pos],dp,pos+1);
        
        dp[pos][target][precolor] = ans;
        return ans;
        
    }
    
public:
    int minCost(vector<int>& house, vector<vector<int>>& cost, int m, int n, int target) {
        
        int curNeighbours = calNeighbours(house);
        if(curNeighbours>target||target==0)
            return -1;
        
        vector<vector<vector<int>>> dp(m,vector<vector<int>> (target+1,vector<int>(n+1,-1)));
        
        int preColor = 0,pos =0 ,ans ,res = INT_MAX;
        
        if(house[pos]!=0)
            res = calMinCost(house,cost,m,n,target-1,house[pos],dp,pos+1);
        else
        {
            for(int i=1;i<=n;i++)
            {
                ans = calMinCost(house,cost,m,n,target-1,i,dp,pos+1);
                if(ans!=INT_MAX)
                    res = min(res,ans+cost[pos][i-1]);
            }
        }
        if(res==INT_MAX)
            return -1;
        return res;
    }
};