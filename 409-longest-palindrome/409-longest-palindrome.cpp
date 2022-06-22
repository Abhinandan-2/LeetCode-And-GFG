class Solution {
public:
    int longestPalindrome(string a) {
        
        int n = a.size(),ans=0,f=0;
        unordered_map<char,int> m;
        for(auto i:a)
            m[i]++;
        for(auto i:m)
        {
            if(i.second%2==0)
                ans+= i.second;
            else
            {
                f=1;
                ans+= (i.second-1);
            }
        }
        if(f==1)
            ans++;
        return ans;
        
    }
};