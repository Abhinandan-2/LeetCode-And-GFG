class Solution {
public:
    
    
    void dfs(vector<vector<int>> &a,int i,int j,int x[],int y[],int &f)
    {
        
        a[i][j] = f;
        f++;
        int n = a.size() , m = a[0].size();
        
        int x1,y1;
        
        for(int k=0;k<4;k++)
        {
            x1 = i+x[k];
            y1 = j+y[k];
            if(x1>=0&&x1<n&&y1>=0&&y1<m&&a[x1][y1]==1)
            {
                dfs(a,x1,y1,x,y,f);
            }
        }
        
        return ;
        
        
    }
        
        
    
    int maxAreaOfIsland(vector<vector<int>>& a) {
        
        int n = a.size(), m = a[0].size(),f;
        
        int x[] = {0,0,1,-1};
        int y[] = {1,-1,0,0};
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==1)
                {
                    f = 2;
                    dfs(a,i,j,x,y,f);
                }
            }
        }
        
        int ans =0 ;
        for(auto i:a)
        {
            for(auto j:i)
                ans = max(ans,j);
        }
        
        if(ans==0)
            return ans;
        return ans-1;
         
        
        
    }
};