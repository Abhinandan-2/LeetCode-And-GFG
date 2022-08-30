class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        
        int n  = a.size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                swap(a[i][j],a[n-j-1][n-i-1]);
            }
        }
        
        for(int i=0;i<n/2;i++)
        {
            swap(a[i],a[n-i-1]);
        }
        
        return;
        
    }
};