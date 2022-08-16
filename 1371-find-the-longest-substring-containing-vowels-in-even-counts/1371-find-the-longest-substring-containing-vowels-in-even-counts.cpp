class Solution {
public:
    
    int findTheLongestSubstring(string a) {
        
        int n = a.size(),ans=0, bit =0,mask;
        unordered_map<int,int> m;
        unordered_map<char,int> vowel;
        vowel['a'] = 0;
        vowel['e'] = 1;
        vowel['i'] = 2;
        vowel['o'] = 3;
        vowel['u'] = 4;
        
        m[bit]=-1;
        for(int i=0;i<n;i++)
        {
            mask = 1;
            if(vowel.count(a[i]))
            {
                mask = mask<<vowel[a[i]];
                bit ^= mask;
                if(m.count(bit))
                    ans= max(ans,i-m[bit]);
                else
                    m[bit] = i;
            }
            else
                ans = max(ans,i-m[bit]);
           
        }
        
        return ans;
        
    }
};