class Solution {
public:
    bool isIsomorphic(string s, string t) {
     
        unordered_map<char,char> ms, mt;
        
        int  n = s.size();
        
        for(int i=0;i<n;i++)
        {
            if(ms.count(s[i]))
            {
                if(ms[s[i]]==t[i])
                    continue;
                return 0;
            }
            else
            {
                if(mt.count(t[i]))
                    return 0;
                ms[s[i]] = t[i];
                mt[t[i]] = s[i];
            }
        }
        
        return 1;
        
    }
};