class Solution {
public:
    bool uniqueOccurrences(vector<int>& a) {
        
        unordered_map<int,int> m,v;
        for(auto i:a) m[i]++;
        for(auto i:m) v[i.second]++;
        for(auto i:v) if(i.second>1) return 0;
        return 1;
        
    }
};