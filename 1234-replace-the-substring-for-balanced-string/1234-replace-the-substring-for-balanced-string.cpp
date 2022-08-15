class Solution {
    
    bool isGreater(unordered_map<char,int> &m,unordered_map<char,int> &mp)
    {
        for(auto i:mp)
        {
            if(i.second>m[i.first])
                return 0;
        }
        return 1;
    }
public:
    int balancedString(string a) {
        
        int n = a.size();
        unordered_map<char,int> m,mp;
        for(auto i:a)
            m[i]++;
        
        int k = n/4;
        
        for(auto i:m)
        {
            // cout<<i.first<<" "<<i.second<<endl;
            if(i.second>k)
                mp[i.first] = i.second-k;
        }
        // for(auto i:mp)
        //     cout<<i.first<<" "<<i.second<<endl;
        m.clear();
        int i=0,j=0,ans =INT_MAX;
        
        while(i<n)
        {
            if(mp.count(a[i]))
            {
                m[a[i]]++;
                while(isGreater(m,mp))
                {
                    while(!mp.count(a[j]))
                        j++;
                    ans = min(ans,i-j+1);
                    m[a[j]]--;
                    j++;
                }
            }
            i++;
        }
        if(ans==INT_MAX)
            return 0;
        return ans;
        
    }
};