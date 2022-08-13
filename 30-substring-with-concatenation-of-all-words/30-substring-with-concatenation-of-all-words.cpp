class Solution {
public:
    vector<int> findSubstring(string a, vector<string>& w) {
        
        int n = a.size() ,m = w[0].size(),len = w.size(),f=0;
        len *= m;
        unordered_map<string,int> mp,v;
        vector<int> ans;
        string h,k;
        for(auto i:w)
            mp[i]++;
        
        int i=0;
        
        while(i<n-len+1)
        {
            h = a.substr(i,len);
            // cout<<h<<" ";
            f=0;
            for(int j=0;j<len;j+=m)
            {
                k = h.substr(j,m);
                v[k]++;
                if(v[k]>mp[k])
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
                ans.push_back(i);
            i++;
            v.clear();
        }
        
        return ans;
        
        
    }
};