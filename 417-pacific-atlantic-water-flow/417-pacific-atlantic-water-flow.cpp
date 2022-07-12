class Solution {
public:
    
    void bfs(vector<vector<int>> &a,vector<vector<int>> &b,queue<pair<int,int>> &q,int x[],int y[])
    {
        int n = a.size() , m= a[0].size(),i,j,x1,y1,h;
        pair<int,int> p;
        
        while(!q.empty())
        {
            h = q.size();
            while(h--)
            {
                p = q.front();
                q.pop();
                i = p.first;
                j = p.second;
                for(int k=0;k<4;k++)
                {
                    x1 = i+x[k];
                    y1 = j+y[k];
                    
                    if(x1>=0&&x1<n&&y1>=0&&y1<m&&b[x1][y1]!=-1&&(a[i][j])<=a[x1][y1])
                    {
                        b[x1][y1]=-1;
                        q.push({x1,y1});
                    }
                    
                }
            }
        }
        return ;
        
    }
    
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& a) {
        
        int n = a.size() , m = a[0].size();
        int x[] = {0,0,1,-1};
        int y[] = {1,-1,0,0};
        queue<pair<int,int>> q,w;
        vector<vector<int>> b,v,ans;
        b = a;
        v = a;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0||j==0)
                {
                    b[i][j] = -1;
                    q.push({i,j});
                }
                if(i==n-1||j==m-1)
                {
                    v[i][j] = -1;
                    w.push({i,j});
                }
            }
        }
        
        bfs(a,b,q,x,y);
        bfs(a,v,w,x,y);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(b[i][j]==-1&&v[i][j]==-1)
                    ans.push_back({i,j});
            }
        }
        
        return ans;
        
        
        
    }
};