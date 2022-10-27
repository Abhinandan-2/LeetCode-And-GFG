class Solution {
public:
    int largestOverlap(vector<vector<int>>& a, vector<vector<int>>& b) {
        
        int n = a.size(),ans = 0 , count =0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                count =0 ;
                for(int x=i;x<n;x++)
                {
                    for(int y=j;y<n;y++)
                    {
                        if(a[x-i][y-j]==1&&b[x][y]==1)
                            count++;
                    }
                }
                ans = max(ans,count);
                count=0;
                for(int x=i;x<n;x++)
                {
                    for(int y=j;y>=0;y--)
                    {
                        if(a[x-i][y+n-j-1]==1&&b[x][y]==1)
                            count++;
                    }
                }
                ans = max(ans,count);
                count=0;
                for(int x=i;x>=0;x--)
                {
                    for(int y=j;y<n;y++)
                    {
                        if(a[x+n-i-1][y-j]==1&&b[x][y]==1)
                            count++;
                    }
                }
                ans = max(ans,count);
                count=0;
                for(int x=i;x>=0;x--)
                {
                    for(int y=j;y>=0;y--)
                    {
                        if(a[x+n-i-1][y+n-j-1]==1&&b[x][y]==1)
                            count++;
                    }
                }
                ans= max(ans,count);
            }
        }
        return ans;
        
         
        
    }
};