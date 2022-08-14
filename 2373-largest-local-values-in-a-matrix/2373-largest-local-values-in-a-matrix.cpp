class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& a) {
        
        int n = a.size() , m = a[0].size(),mn;
        
        vector<int> h;
        vector<vector<int>> ans;
        
        for(int i=0;i<n-2;i++)
        {
            h.clear();
            for(int j=0;j<n-2;j++)
            {
                mn = INT_MIN;
                for(int k=i;k<i+3;k++)
                {
                    for(int p=j;p<j+3;p++)
                    {
                        mn = max(mn,a[k][p]);
                    }
                }
                h.push_back(mn);
            }
            ans.push_back(h);
        }
        
        return ans;
        
    }
};