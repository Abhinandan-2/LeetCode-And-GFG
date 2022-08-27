class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& a) {
        
        int n = a.size(), m = a[0].size(),h;
        
        vector<vector<int>> v(n+m-1);
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                //cout<<j<<" ";
                v[i+j].push_back(a[i][j]);
            }
            //cout<<i<<endl;
        }
        
        for(int i=0;i<v.size();i++)
        {
            h = v[i].size();
            if(i%2==0)
            {
                for(int j=h-1;j>=0;j--)
                {
                    ans.push_back(v[i][j]);
                }
            }
            else
            {
                for(int j=0;j<h;j++)
                {
                    ans.push_back(v[i][j]);
                }
            }
        }
        
        
        return ans;
        
        
        
        
        
        
    }
};