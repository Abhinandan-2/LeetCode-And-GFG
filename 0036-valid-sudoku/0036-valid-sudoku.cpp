class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& a) {
        
        unordered_map<char,int> m;
       // cout<<1;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(a[i][j]!='.'&&m.count(a[i][j]))
                    return 0;
                m[a[i][j]]++;
            }
            m.clear();
        }
        m.clear();
             //   cout<<2;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(a[j][i]!='.'&&m.count(a[j][i]))
                    return 0;
                m[a[j][i]]++;
            }
            m.clear();
        }
        m.clear();
            //cout<<3;

        for(int k=0;k<9;k++)
        {
            for(int i=(k/3)*3;i<(k/3)*3+3;i++)
            {
                for(int j=(k%3)*3;j<(k%3)*3+3;j++)
                {
                    //cout<<i<<j<<" ";
                    if(a[i][j]!='.'&&m.count(a[i][j]))
                    return 0;
                   m[a[i][j]]++;
                }
            }
            m.clear();
        }
        return 1;
    }
};