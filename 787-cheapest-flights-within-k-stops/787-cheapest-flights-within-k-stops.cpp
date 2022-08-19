class Solution {
    
    void dfs(vector<vector<pair<int,int>>> &a,vector<vector<int>> &v,int s,int d,int k,int val)
    {
        int n = a.size();
        
        if(v[s][k]<=val)
            return ;
        
        for(int i=k;i<=n;i++)
        {
            if(v[s][i]<=val)
                break;
            v[s][i] = val;
        }
        
        if(s==d)
            return ;
        
        for(int i=0;i<a[s].size();i++)
            dfs(a,v,a[s][i].first,d,k+1,val+a[s][i].second);
        
        return ;
        
    }
    
    
public:
    int findCheapestPrice(int n, vector<vector<int>>& ed, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>> a(n);
        
        for(int i=0;i<ed.size();i++)
            a[ed[i][0]].push_back({ed[i][1],ed[i][2]});
        
        vector<vector<int>> ans(n,vector<int> (n+1,INT_MAX));
        
        dfs(a,ans,src,dst,0,0);
        
        int res = ans[dst][k+1];
        
        if(res==INT_MAX)
            return -1;
        
        return res;
        
        
    }
};