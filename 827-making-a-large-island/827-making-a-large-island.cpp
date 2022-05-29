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
                if(i1>=0&&i1<n&&j1>=0&&j1<m&&a[i1][j1]==1)
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
        
        int n = a.size() , m = a[0].size(),mn=2;
        int x1[] = {0,0,1,-1};
        int y1[] = {1,-1,0,0};
        unordered_map<int,int> mapCount,help;
        mapCount[0] = 0;
        int count ,area;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==1)
                {
                    area = call(a,i,j,x1,y1,mn);
                    mapCount[mn] = area;
                    mn++;
                }
            }
        }
        
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