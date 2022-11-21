class Solution {
public:
    int nearestExit(vector<vector<char>>& a, vector<int>& b) {
        
        int n = a.size() , m = a[0].size(),h,ans=0,x1,y1;
        
        int x[] = {0,0,-1,1};
        int y[] = {1,-1,0,0};
        
        queue<pair<int,int>> q;
        //pair<int,int> p;
        
        q.push({b[0],b[1]});
        a[b[0]][b[1]] = '+';
        
        while(!q.empty())
        {
            h = q.size();
            ans++;
            while(h--)
            {
                auto [i,j] = q.front();
                q.pop();
                
                for(int k=0;k<4;k++)
                {
                    x1 = i+x[k];
                    y1 = j+y[k];
                    if(x1>=0&&x1<n&&y1>=0&&y1<m&&a[x1][y1]=='.')
                    {
                        if(x1==0||x1==n-1||y1==0||y1==m-1)
                            return ans;
                        q.push({x1,y1});
                        a[x1][y1] = '+';
                    }
                }
                
            }
        }
        return -1;
        
         
        
        
    }
};