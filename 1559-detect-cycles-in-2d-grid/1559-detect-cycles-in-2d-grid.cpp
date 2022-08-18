class Solution {
    
    bool call(vector<vector<char>> &a,vector<vector<int>> &v,int i,int j,int x[],int y[],int i1,int j1)
    {
        int x1,y1,n = a.size(), m=a[0].size();
        if(v[i][j]==1)
            return 1;
        v[i][j]  =1;
        
        for(int k=0;k<4;k++)
        {
            x1 =i+x[k];
            y1 = j+y[k];
            if(x1>=0&&x1<n&&y1>=0&&y1<m&&(x1!=i1||y1!=j1)&&a[x1][y1]==a[i][j])
            {
                if(call(a,v,x1,y1,x,y,i,j))
                    return 1;
            }
        }
        return 0;
    }
    
public:
    bool containsCycle(vector<vector<char>>& a) {
        
        int n = a.size() , m=a[0].size();
        int x[] = {0,0,1,-1};
        int y[] = {1,-1,0,0};
        vector<vector<int>> v(n,vector<int> (m,-1));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]==-1&&call(a,v,i,j,x,y,-1,-1))
                    return 1;
            }
        }
        return 0;
    }
};