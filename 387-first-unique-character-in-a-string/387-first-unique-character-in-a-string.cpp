class Solution {
public:
    int firstUniqChar(string a) {
        
        int n = a.size();
        unordered_map<char,int> m;
        for(auto i:a)
            m[i]++;
        
        for(int i=0;i<n;i++)
            if(m[a[i]]==1)
                return i;
        return -1;
        
    }
};