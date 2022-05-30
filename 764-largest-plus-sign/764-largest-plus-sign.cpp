class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& b) {
        
        vector<vector<int>> a(n,vector<int> (n,1)),l,r,u,d;
        for(int i=0;i<b.size();i++)
            a[b[i][0]][b[i][1]]=0;
        l = a;
        r = a;
        u = a;
        d = a;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(a[i][j]==1)
                    l[i][j] = l[i][j-1]+1;
            }
            for(int j=n-2;j>=0;j--)
            {
                if(a[i][j]==1)
                    r[i][j] = r[i][j+1]+1;
            }
        }
        for(int j=0;j<n;j++)
        {
            for(int i=1;i<n;i++)
            {
                if(a[i][j]==1)
                    u[i][j] = u[i-1][j]+1;
            }
            for(int i=n-2;i>=0;i--)
            {
                if(a[i][j]==1)
                    d[i][j] = d[i+1][j]+1;
            }
        }
        
        int ans =0 ,h;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]==1)
                {
                    if(i==0||i==n-1||j==0||j==n-1)
                        ans= max(ans,1);
                    else
                    {
                        h = min(min(l[i][j-1],r[i][j+1]),min(u[i-1][j],d[i+1][j]));
                        ans = max(ans,h+1);
                    }
                }
            }
        }
        return ans;
        
    }
};