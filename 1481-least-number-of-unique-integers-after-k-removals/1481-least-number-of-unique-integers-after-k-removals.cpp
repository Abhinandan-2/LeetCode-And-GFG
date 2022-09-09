class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& a, int k) {
        
        unordered_map<int,int> m;
        int n = a.size();
        
        for(auto i:a)
            m[i]++;
        
        vector<int> v;
        for(auto i:m)
        {
            v.push_back(i.second);
        }
        sort(v.begin(),v.end());
        int i=0;
        n = v.size();
        while(i<n&&k>=v[i])
        {
            k -= v[i];
            i++;
        }
        return n-i;
        
    }
};