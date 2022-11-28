class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& a) {
        
        unordered_map<int,int> m;
        int n = a.size();
        for(int i=0;i<n;i++)
        {
            m[a[i][0]]++;
            m[a[i][0]]--;
            m[a[i][1]]++;
        }
        
        vector<vector<int>> ans(2);
        
        for(auto i:m)
        {
            if(i.second==0)
                ans[0].push_back(i.first);
            else if(i.second==1)
                ans[1].push_back(i.first);
        }
        
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        
        return ans;
        
        
    }
};