class Solution {
public:
    bool checkIfPangram(string a) {
        unordered_map<char,int> m;
        for(auto i:a) m[i]++;
        if(m.size()==26) return 1;
        return 0;  
    }
};