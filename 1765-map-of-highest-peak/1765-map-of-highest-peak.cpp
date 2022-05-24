class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& a) {
        
        int n = a.size() , m = a[0].size(),h,k=0,x1,y1;
        int x[] = {0,0,1,-1};
        int y[] = {1,-1,0,0};
        queue<pair<int,int>> q;
        pair<int,int> p;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==1)
                {
                    a[i][j] = 0;
                    q.push({i,j});
                }
                else
                    a[i][j] = -1;
            }
        }
        
        while(!q.empty())
        {
            h = q.size();
            k++;
            while(h--)
            {
                p = q.front();
                q.pop();
                
                for(int i=0;i<4;i++)
                {
                    x1 = p.first+x[i];
                    y1 = p.second+y[i];
                    if(x1>=0&&x1<n&&y1>=0&&y1<m&&a[x1][y1]==-1)
                    {
                        q.push({x1,y1});
                        a[x1][y1] = k;
                    }
                }
                
                
            }
        }
        return a;
        
        
        
        
    }
};