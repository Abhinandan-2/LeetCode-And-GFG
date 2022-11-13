class Solution {
public:
    string reverseWords(string a) {
        
        stringstream c(a);
        string h;
        vector<string> v;
        while(c>>h)
        {
            v.push_back(h);
        }
        
        string ans="", p = " ";
        int n = v.size();
        for(int i=n-1;i>=0;i--)
        {
            ans += v[i];
            if(i!=0)
            ans += p;
        }
        return ans;
        
    }
};