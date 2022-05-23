class Solution {
public:
    bool areOccurrencesEqual(string a) {
        
        unordered_map<char,int> m;
        
        for(auto i:a)
            m[i]++;
        
        int f=0;
        for(auto i:m)
        {
            if(f==0)
                f = i.second;
            else
            {
                if(i.second!=f)
                    return 0;
            }
        }
        return 1;
        
        
    }
};