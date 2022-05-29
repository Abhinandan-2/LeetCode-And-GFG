class Solution {
    
    int call(vector<vector<int>> &a,int i,int j,int x1[],int y1[],int mn)
    {
        int n = a.size() , m = a[0].size();
        queue<pair<int,int>> q;
        pair<int,int> p;
        int count =0,i1,j1,x,y;
        a[i][j] = mn;
        q.push({i,j});
        while(!q.empty())
        {
            p = q.front();
            q.pop();
            x = p.first;
            y = p.second;
            count++;
            for(int k=0;k<4;k++)
            {
                i1 = x+x1[k];
                j1 = y+y1[k];
                if(i1>=0&&i1<n&&j1>=0&&j1<m&&a[i1][j1]==-2)
                {
                    a[i1][j1] = mn;
                    q.push({i1,j1});
                }
            }
            
        }
        
        return count;
    }
    
public:
    int largestIsland(vector<vector<int>>& a) {
        
        int n = a.size() , m = a[0].size(),mn=1;
        int x1[]  ={0,0,1,-1};
        int y1[]  = {1,-1,0,0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==1)
                    a[i][j]=-2;
            }
        }
        unordered_map<int,int> mapCount,help;
        mapCount[0] = 0;
        int count ;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==-2)
                {
                    count = call(a,i,j,x1,y1,mn);
                    mapCount[mn] = count;
                    mn++;
                }
            }
        }
        // for(auto i:a)
        // {
        //     for(auto j:i)
        //         cout<<j<<" ";
        //     cout<<endl;
        // }
        int res =0,f=0,x,y;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==0)
                {
                    f=1;
                    for(int k=0;k<4;k++)
                    {
                        x = i+x1[k];
                        y = j+y1[k];
                        if(x>=0&&x<n&&y>=0&&y<m)
                            help[a[x][y]]++;
                    }
                    count =0;
                    for(auto k:help)
                    {
                        count += mapCount[k.first];
                    }
                    count++;
                    help.clear();
                    res = max(res,count);
                }
            }
        }
        if(f==0)
            return n*m;
        return res;
        
        
        
    }
};

/*

class Solution {
    
    map<pair<int,int>,int> call(vector<vector<int>> &a,int i,int j,int x1[],int y1[])
    {
        int n = a.size() , m = a[0].size();
        map<pair<int,int>,int> ans,vis;
        queue<pair<int,int>> q;
        int count =0,i1,j1;
        vis[{i,j}]=1;
        q.push({i,j});
        while(!q.empty())
        {
            auto &[x,y] = q.front();
            q.pop();
            if(x+1>=n||a[x+1][y]==0)
                ans[{x,y}]=1;
            if(!ans.count({x,y})&&(y+1>=m||a[x][y+1]==0))
                ans[{x,y}]=1;
            if(!ans.count({x,y})&&(y-1<0||a[x][y-1]==0))
                ans[{x,y}]=1;
            if(!ans.count({x,y})&&(x-1<0||a[x-1][y]==0))
                ans[{x,y}]=1;
            count++;
            for(int k=0;k<4;k++)
            {
                i1 = x+x1[k];
                j1 = y+y1[k];
                if(i1>=0&&i1<n&&j1>=0&&j1<m&&a[i1][j1]==-2&&!vis.count({i1,j1}))
                {
                    vis[{i1,j1}]=1;
                    q.push({i1,j1});
                }
            }
            
        }
        
        for(auto k:vis)
            a[k.first.first][k.first.second] = count;
        
        return ans;
        
    }
    
public:
    int largestIsland(vector<vector<int>>& a) {
        
        int n = a.size() , m = a[0].size();
        int x1[]  ={0,0,1,-1};
        int y1[]  = {1,-1,0,0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==1)
                    a[i][j]=-2;
            }
        }
        vector<map<pair<int,int>,int>> ans;
        map<pair<int,int>,int> bd;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==-2)
                {
                    bd = call(a,i,j,x1,y1);
                    ans.push_back(bd);
                }
            }
        }
        
        int res =0 ,x,y,i1,i2,j1,j2;
        if(ans.size()==0)
            return 1;
        for(int i=0;i<ans.size();i++)
        {
            map<pair<int,int>,int> &p = ans[i];
            
            for(auto k:p)
            {
                x = k.first.first;
                y = k.first.second;
                res = max(res,a[x][y]);
                for(int j=0;j<4;j++)
                {
                    i1 = x+x1[j];
                    j1 = y+y1[j];
                    if(i1>=0&&i1<n&&j1>=0&&j1<m&&a[i1][j1]==0)
                    {
                        //res = max(res,a[x][y]+1);
                        count =0;
                        for(int l=0;l<4;l++)
                        {
                            i2 = i1+x1[l];
                            j2 = j1+y1[l];
                            if(i2>=0&&i2<n&&j2>=0&&j2<m&&!p.count({i2,j2}))
                            {
                                // res = max(res,a[x][y]+a[i2][j2]+1);
                                count += a[i2][j2];
                            }
                        }
                    }
                }
            }
            
        }
        return res;
        
        
    }
};

*/