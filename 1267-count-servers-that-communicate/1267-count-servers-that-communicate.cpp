class Solution {
public:
    int countServers(vector<vector<int>>& a) {
        
        int n = a.size() , m = a[0].size(),f=0,total =0;
        vector<int> row,col;
        for(int i=0;i<n;i++)
        {
            f =0;
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==1)
                    f++;
            }
            if(f==1)
                row.push_back(i);  
            total += f;
        }
        
        for(int i=0;i<m;i++)
        {
            f =0;
            for(int j=0;j<n;j++)
            {
                if(a[j][i]==1)
                    f++;
                if(f>=2)
                    break;
            }
            if(f==1)
                col.push_back(i);    
        }
        
        int ans =0;
        for(int i=0;i<row.size();i++)
        {
            for(int j=0;j<col.size();j++)
            {
                if(a[row[i]][col[j]]==1)
                    ans++;
            }
        }
        
        return total-ans;
        
        
    }
};