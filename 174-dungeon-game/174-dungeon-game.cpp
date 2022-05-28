class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& a) {
        
        int n = a.size() , m = a[0].size(),h;
        
        if(a[n-1][m-1]>0)
            a[n-1][m-1] =0;
        
        for(int i=n-2;i>=0;i--)
        {
            a[i][m-1] += a[i+1][m-1];
            if(a[i][m-1]>0)
                a[i][m-1]=0;
        }
        
        for(int j=m-2;j>=0;j--)
        {
            a[n-1][j] += a[n-1][j+1];
            if(a[n-1][j]>0)
                a[n-1][j]=0;
        }
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=m-2;j>=0;j--)
            {
                h = max(a[i+1][j],a[i][j+1]);
                a[i][j] += h;
                if(a[i][j]>0)
                    a[i][j] = 0;
            }
        }
       
        return abs(a[0][0])+1;
        
        
        
        
    }
};