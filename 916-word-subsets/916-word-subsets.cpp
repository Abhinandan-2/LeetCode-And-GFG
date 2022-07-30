class Solution {
public:
    vector<string> wordSubsets(vector<string>& a, vector<string>& b) {
        
        int n = a.size() , m = b.size();
        unordered_map<char,int> mp,v;
        
        for(auto i:b)
        {
            for(auto j:i)
                v[j]++;
            for(auto j:v)
                mp[j.first] = max(mp[j.first],j.second);
            v.clear();
        }
        
        vector<string> ans;
        int f=0;
        for(int i=0;i<n;i++)
        {
            f=0;
            for(auto j:a[i])
                v[j]++;
            for(auto j:mp)
            {
                if(v[j.first]<j.second)
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
                ans.push_back(a[i]);
            v.clear();
        }
        
        return ans;
        
    }
};