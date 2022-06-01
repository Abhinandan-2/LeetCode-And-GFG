class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& a, int t) {
        
        int n = a.size() ,  m = a[0].size();
        vector<int> help(m+1,0);
        for(int i=0;i<n;i++)
             a[i].insert(a[i].begin(),0);
        a.insert(a.begin(),help);
        
        n = a.size();
        m = a[0].size();
        int sum ,ans =0;
        for(int i=1;i<n;i++)
            for(int j=1;j<m;j++)
                a[i][j] += (a[i-1][j]+a[i][j-1]-a[i-1][j-1]);
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                for(int x=1;x<=i;x++)
                {
                    for(int y=1;y<=j;y++)
                    {
                        sum = a[i][j];
                        sum -= a[x-1][j];
                        sum -= a[i][y-1];
                        sum += a[x-1][y-1];
                        if(sum==t)
                            ans++;
                    }
                }
            }
        }
        
        return ans;
        
        
        
        
    }
};