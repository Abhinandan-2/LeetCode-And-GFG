class Solution {
    
    bool isSame(string &a,string &b)
    {
        int n = a.size() , m = b.size();
        if(n!=m)
            return 0;
        unordered_map<char,char> mp,v;
        
        for(int i=0;i<n;i++)
        {
            if(mp.count(a[i]))
            {
                if(b[i]!=mp[a[i]])
                    return 0;
            }
            else
            {
                if(v.count(b[i]))
                    return 0;
                mp[a[i]] = b[i];
                v[b[i]] = '0';
            }
        }
        return 1;
        
    }
    
public:
    vector<string> findAndReplacePattern(vector<string>& a, string b) {
        
        vector<string> ans;
        int n = a.size();
        
        for(int i=0;i<n;i++)
        {
            if(isSame(a[i],b))
                ans.push_back(a[i]);
        }
        
        return ans;
        
    }
};