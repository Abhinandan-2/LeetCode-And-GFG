class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& a) {
        
        int n = a.size() , m= a[0].size();
        vector<int> t;
        int i= n-1,j,h;
        
        while(i>=0)
        {
            h = i ;j = 0;
            while(h<n&&j<m)
                t.push_back(a[h++][j++]);
            h = i;j=0;
            sort(t.begin(),t.end());
            for(int k=0;k<t.size();k++)
                a[h++][j++] = t[k];
            t.clear();
            i--;
        }
        i = 1;
        while(i<m)
        {
            j = i ;h = 0;
            while(h<n&&j<m)
                t.push_back(a[h++][j++]);
            j = i;h = 0;
            sort(t.begin(),t.end());
            for(int k=0;k<t.size();k++)
                a[h++][j++] = t[k];
            t.clear();
            i++;
        }
        
        return a;
        
    }
};