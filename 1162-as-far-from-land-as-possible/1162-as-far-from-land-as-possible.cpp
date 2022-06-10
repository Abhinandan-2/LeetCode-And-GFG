class Solution {
public:
    int maxDistance(vector<vector<int>>& a) {
        
        int n = a.size(),ans=-1,h;
        queue<pair<int,int>> q;
        pair<int,int> p;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]==1)
                {
                    q.push({i,j});
                    a[i][j] = -1; 
                }
            }
        }
        int x[] = {0,0,1,-1};
        int y[] = {1,-1,0,0};
        int i,j;
        while(!q.empty())
        {
            h = q.size();
            // cout<<h<<" ";
            ans++;
            while(h--)
            {
                p = q.front();
                q.pop();
                for(int k=0;k<4;k++)
                {
                    i = p.first+x[k];
                    j = p.second+y[k];
                    if(i>=0&&i<n&&j>=0&&j<n&&a[i][j]==0)
                    {
                        q.push({i,j});
                        a[i][j] = -1;
                    }
                }
            }
        }
        
        if(ans==0)
            return -1;
        return ans;
        
    }
};