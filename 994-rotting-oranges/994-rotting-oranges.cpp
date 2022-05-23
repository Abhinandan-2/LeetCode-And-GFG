class Solution {
public:

    
    // void dfs(vector<vector<int>> &a,int i,int j,int x[],int y[])
    // {
    //     int n = a.size() , m = a[0].size() ,x1,y1;
    //     a[i][j] = 2;
        // for(int k=0;k<4;k++)
        // {
        //     x1 = i+x[k];
        //     y1 = j+y[k];
        //     if(x1>=0&&x1<n&&y1>=0&&y1<m&&a[x1][y1]==1)
        //     {
        //         dfs(a,x1,y1,x,y);
        //     }
        // }
    //     return ;
    // }
    
    int orangesRotting(vector<vector<int>>& a) {
        
        int n = a.size() , m = a[0].size(),i,j,x1,y1 ;
        int x[] = {0,0,1,-1};
        int y[] = {1,-1,0,0};
        
        queue<pair<int,int>> q,v,h;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                //cout<<i<<" "<<j<<" ";
                if(a[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        int ans =0 ;
        pair<int,int> p;
        while(!q.empty())
        {
            //cout<<23;
            p = q.front();
            q.pop();
            i = p.first;
            j = p.second;
            for(int k=0;k<4;k++)
            {
                x1 = i+x[k];
                y1 = j+y[k];
                if(x1>=0&&x1<n&&y1>=0&&y1<m&&a[x1][y1]==1)
                {
                    a[x1][y1] = 2;
                    v.push({x1,y1});
                }
            }
            if(q.empty())
            {
                q = v;
                if(!q.empty())
                ans++;
                v = h;
            }
        }
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(a[i][j]==1 )
                    return -1;
        
        
        return ans;
        
    }
};