class Solution {
public:
    string decodeCiphertext(string a, int n) {
        
        int len = a.size();
        int m = len/n,k=0;
        
        vector<vector<char>> v(n,vector<char>(m));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                v[i][j] = a[k++];
            }
        }
        string ans;
        int h=0,i=0,j=0;
        while(h<m)
        {
            ans.push_back(v[i][j]);
            i++;
            j++;
            if(i==n||j==m)
            {
                h++;
                i=0;
                j=h;
            }
        }
        while(ans.size()>0&&ans.back()==' ')
            ans.pop_back();
        return ans;
        
        
    }
};