class Solution {
public:
    int minimumTotal(vector<vector<int>>& a) {
        
        int n = a.size(),ans;
        if(n==1)
            return a[0][0];
        for(int i=1;i<n;i++)
        {
            ans = INT_MAX;
            for(int j=0;j<=i;j++)
            {
                if(j==0)
                    a[i][j] += a[i-1][j];
                else if(j==i)
                    a[i][j] += a[i-1][j-1];
                else
                    a[i][j] += min(a[i-1][j],a[i-1][j-1]);
                ans = min(ans,a[i][j]);
            }
        }
        return ans;
        
        
    }
};