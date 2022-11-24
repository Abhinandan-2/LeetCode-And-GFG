class Solution {
public:
    
    
    bool bt(vector<vector<char>> &a,int i,int j,int x[],int y[] ,vector<vector<int>> &v,int n,int m,string t, int k)
    {
        int p = t.size();
        if(k==p)
            return 1;
        if(a[i][j]!=t[k])
            return 0;
        if(k+1==p)
            return 1;
        int x1 , y1;
        v[i][j] = 1;
        for(int l=0;l<4;l++)
        {
            x1 = i+x[l];
            y1 = j+y[l];
            if(x1>=0&&x1<n&&y1>=0&&y1<m&&v[x1][y1]==0)
            {
                if(bt(a,x1,y1,x,y,v,n,m,t,k+1))
                    return 1;
            }
        }
        v[i][j]=0;
        return 0;
    }
    
    
    bool exist(vector<vector<char>>& a, string t) {
        
        int n = a.size() , m = a[0].size();
        vector<vector<int>> v(n,vector<int> (m,0));
        int x[] = {0,0,1,-1};
        int y[] = {1,-1,0,0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(bt(a,i,j,x,y,v,n,m,t,0))
                    return 1;
            }
        }
        return 0;
        
        
    }
};