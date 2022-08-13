class Solution {
public:
    int reductionOperations(vector<int>& a) {
        
        int n = a.size();
        unordered_map<int,int> m;
        for(auto i:a)
            m[i]++;
        
        vector<pair<int,int>> v;
        for(auto i:m)
            v.push_back(i);
        
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        
        n = v.size();
        if(n==1)
            return 0;
        int ans = v[0].second;
        for(int i=1;i<n-1;i++)
        {
            v[i].second += v[i-1].second;
            ans += v[i].second;
        }
        
        return ans;
        
    }
};