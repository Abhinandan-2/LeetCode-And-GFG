class Solution {
    
    void backtrack(vector<vector<int>> &a,int &ans,int &c,int &t,int i,int j,int x[],int y[])
    {
        int n = a.size() , m =a[0].size(),x1,y1;
        
        if(a[i][j]==2)
        {
            c++;
            if(c==t)
                ans++;
            c--;
            return ;
        }
        
        a[i][j] = 3;
        c++;
        
        for(int k=0;k<4;k++)
        {
            x1 = i+x[k];
            y1 = j+y[k];
            if(x1>=0&&x1<n&&y1>=0&&y1<m&&(a[x1][y1]==0||a[x1][y1]==2))
            {
                backtrack(a,ans,c,t,x1,y1,x,y);
            }
        }
        c--;
        a[i][j] = 0;
        return ;   
    }
    
public:
    int uniquePathsIII(vector<vector<int>>& a) {
        
        
        int n = a.size(),m = a[0].size(),ans =0 , count =0,t=0,s,e ;
        int x[] = {0,0,1,-1};
        int y[] = {1,-1,0,0};
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(a[i][j]==-1)
                    t++;
                if(a[i][j]==1)
                {
                    s = i;
                    e = j;
                }
            }
        t = (n*m)-t;
        
        backtrack(a,ans,count,t,s,e,x,y);
        return ans;
        
    }
};