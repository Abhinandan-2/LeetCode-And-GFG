class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& a, vector<vector<int>>& t) {
        
        
        vector<int> ans;
        vector<pair<string,int>> v;
        int res , len;
        string h;
        for(int i=0;i<t.size();i++)
        {
            len = a[0].size();
            for(int j=0;j<a.size();j++)
            {
                h = a[j].substr(len-t[i][1],t[i][1]);
                v.push_back({h,j});
            }
            sort(v.begin(),v.end());
            res  = v[t[i][0]-1].second;
            v.clear();
            ans.push_back(res);
        }
        
        return ans;
        
        
    }
};