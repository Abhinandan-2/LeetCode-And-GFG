class Solution {
public:
    bool isAnagram(string a, string b) {
        
        unordered_map<char,int> m;
        for(auto i:a)
            m[i]++;
        
        for(auto i:b)
        {
            if(!m.count(i))
                return 0;
            m[i]--;
            if(m[i]==0)
                m.erase(i);
        }
        if(m.size()==0)
        return 1;
        return 0;
        
    }
};