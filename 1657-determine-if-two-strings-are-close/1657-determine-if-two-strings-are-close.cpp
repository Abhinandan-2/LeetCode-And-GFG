class Solution {
public:
    bool closeStrings(string a, string b) {
        int n = a.size() , m = b.size();
        if(n!=m) return 0;
        unordered_map<int,int> f,s,v,q;
        for(auto i:a) f[(int)i]++;
        for(auto i:b) s[(int)i]++;
        for(int c=0;c<=26;c++) if((f.count(c+97)&&!s.count(c+97))||(!f.count(c+97)&&s.count(c+97))) return 0;
        for(auto i:f) v[i.second]++;
        for(auto i:s) q[i.second]++;
        if(v!=q) return 0;
        return 1;
    }
};