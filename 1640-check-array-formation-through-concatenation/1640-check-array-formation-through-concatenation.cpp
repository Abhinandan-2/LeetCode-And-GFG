class Solution {
public:
    bool canFormArray(vector<int>& a, vector<vector<int>>& v) {
        
        int n = a.size();
        unordered_map<int,int> m;
        
        for(int i=0;i<v.size();i++)
            m[v[i][0]] = i;
        
        int i=0,j;
        while(i<n)
        {
            if(m.count(a[i]))
            {
                j = m[a[i]];
                for(int k=0;k<v[j].size();k++)
                {
                    if(a[i]!=v[j][k])
                        return 0;
                    i++;
                }
            }
            else
                return 0;
        }
        
        return 1;
        
    }
};