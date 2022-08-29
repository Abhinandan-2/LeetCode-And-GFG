class Solution {
public:
    
    void dfs(vector<vector<char>> &a,int i,int j,int x[],int y[])
    {
        int n = a.size() , m = a[0].size(),x1,y1;
        a[i][j] = '0';
        for(int k=0;k<4;k++)
        {
            x1 = i+x[k];
            y1 = j+y[k];
            if(x1>=0&&x1<n&&y1>=0&&y1<m&&a[x1][y1]=='1')
                dfs(a,x1,y1,x,y);
        }
        return ;
    }
    
    int numIslands(vector<vector<char>>& a) {
        
        int n = a.size() , m = a[0].size(),ans=0;
        int x[]  = {0,0,1,-1};
        int y[] = {1,-1,0,0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]=='1')
                {
                    ans++;
                    dfs(a,i,j,x,y);
                }
            }
        }
        
        return ans;
        
        
    }
};