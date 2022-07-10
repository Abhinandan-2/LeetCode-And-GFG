class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int t) {
        
        int n = a.size() , m = a[0].size();
        
        int i=0 , j = m-1;
        
        while(i<n&&j>=0)
        {
            if(a[i][j]==t)
                return 1;
            if(a[i][j]>t)
                j--;
            else
                i++;
        }
        
        return 0;
        
        
        
    }
};