class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& a, int k) {
        int n = a.size(),i=0;
        unordered_map<int,int> m;
        for(auto i:a) m[i]++;
        vector<int> v;
        for(auto i:m) v.push_back(i.second);
        sort(v.begin(),v.end());
        n = v.size();
        while(i<n&&k>=v[i]) k -= v[i++];
        return n-i;
    }
};