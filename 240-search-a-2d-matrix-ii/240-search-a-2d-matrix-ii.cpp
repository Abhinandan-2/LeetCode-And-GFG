class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int t) {
        
        int n = a.size() , m = a[0].size();
        
        int i=n-1 ,j = 0;
        while(i>=0&&j<m)
        {
            if(a[i][j]==t)
                return 1;
            if(a[i][j]>t)
                i--;
            else
                j++;
        }
        return 0;
    }
};