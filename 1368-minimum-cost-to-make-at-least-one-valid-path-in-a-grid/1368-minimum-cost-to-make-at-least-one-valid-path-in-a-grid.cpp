

class Solution {
public:
    
    struct com
    {
        bool operator() (vector<int> &a,vector<int> &b)
        {
            return a[2]>b[2];
        }  
    };
    
    int minCost(vector<vector<int>>& a) {
        
        int n = a.size() , m = a[0].size();
        int x[] = {0,0,1,-1};
        int y[] = {1,-1,0,0};
        
        vector<vector<int>> dp(n,vector<int> (m,INT_MAX));
        vector<vector<bool>> v(n,vector<bool> (m,false));
        
        priority_queue<vector<int>,vector<vector<int>> , com> q;
        vector<int> p;
        int x1,y1,cost;
        dp[0][0]=0 ;
        q.push({0,0,0});
        
        while(!q.empty())
        {
            p = q.top();
            q.pop();
            v[p[0]][p[1]] = true ;
            
            for(int k=0;k<4;k++)
            {
                x1 = p[0]+x[k];
                y1 = p[1]+y[k];
                cost = a[p[0]][p[1]] == k+1 ? 0 :1 ;
                if(x1>=0&&x1<n&&y1>=0&&y1<m&&v[x1][y1]==false&&p[2]+cost<dp[x1][y1])
                {
                    dp[x1][y1] = p[2]+cost;
                    q.push({x1,y1,dp[x1][y1]});
                }
            }
            
        }
        
        return dp[n-1][m-1];
         
    }
};