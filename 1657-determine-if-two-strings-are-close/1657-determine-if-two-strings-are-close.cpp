class Solution {
public:
    bool closeStrings(string a, string b) {
        unordered_map<char,int> m,v;
        unordered_map<int,int> x,y;
        for(auto i:a) m[i]++;
        for(auto i:b) v[i]++;
        for(auto i:m) {if(!v.count(i.first)) return 0; x[i.second]++;}
        for(auto i:v) {if(!m.count(i.first)) return 0; y[i.second]++;}
        if(x!=y) return 0;
        return 1;
    }
};