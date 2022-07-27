class Solution {
public:
    long long maxPoints(vector<vector<int>>& a) {
        
        int n = a.size() , m = a[0].size();
        
        vector<vector<long long>> ans(n,vector<long long> (m,0));
        vector<long long> left(m,0) , right(m,0);
        long long res =0 ;
        
        for(int j=0;j<m;j++)
        {
            ans[0][j] = a[0][j];
            res = max(res,ans[0][j]);
        }
        for(int i=1;i<n;i++)
        {
            left[0] = ans[i-1][0];
            for(int j=1;j<m;j++)
                left[j] = max(ans[i-1][j],left[j-1]-1);
            
            right[m-1] = ans[i-1][m-1];
            for(int j=m-2;j>=0;j--)
                right[j] = max(ans[i-1][j],right[j+1]-1);
            
            for(int j=0;j<m;j++)
            {
                ans[i][j] = a[i][j]+max(left[j],right[j]);
                res = max(res,ans[i][j]);
            }
            
        }
        
        return res;  
        
    }
};