class NumMatrix {
    
    vector<vector<int>> a;
    
public:
    NumMatrix(vector<vector<int>>& v) {
        
        int n = v.size() , m = v[0].size();
        for(int i=0;i<n;i++)
            v[i].insert(v[i].begin(),0);
        vector<int> p(m+1,0);
        v.insert(v.begin(),p);
        m = v[0].size();
        n = v.size();
        for(int i=1;i<n;i++)
            for(int j=1;j<m;j++)
                v[i][j] += (v[i-1][j]+v[i][j-1]-v[i-1][j-1]);
        
        a = v;
        return ;
        
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        row1++;
        col1++;
        row2++;
        col2++;
        int ans = a[row2][col2];
        ans -= a[row2][col1-1];
        ans -= a[row1-1][col2];
        ans += a[row1-1][col1-1];
        return ans;
        // return 0;
        
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */