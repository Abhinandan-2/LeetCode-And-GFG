class Solution {
public:
    
    static bool com(pair<int,int> &a,pair<int,int> &b)
    {
        return a.second<b.second;
    }
    
    vector<int> advantageCount(vector<int>& a, vector<int>& b) {
        
        int n =a.size();
        vector<pair<int,int>> v(n),res(n);
        vector<int> ans(n);
        
        for(int i=0;i<n;i++)
        {
            v[i] = {b[i],i};
        }
        
        sort(v.begin(),v.end());
        
        multiset<int> s;
        for(int i=0;i<n;i++)
            s.insert(a[i]);
        
        for(int i=0;i<n;i++)
        {
            auto it = s.upper_bound(v[i].first);
            if(it==s.end())
                res[i].first = -1;
            else
            {
                res[i].first = *it;
                s.erase(it);
            }
            res[i].second = v[i].second;
            // cout<<res[i].first<<" "<<res[i].second<<" "<<s.size()<<endl;
        }
        
        for(int i=0;i<n;i++)
        {
            if(res[i].first==-1)
            {
                res[i].first = *(s.begin());
                s.erase(s.begin());
            }
        }
        
        sort(res.begin(),res.end(),com);
        
        for(int i=0;i<n;i++)
            ans[i] = res[i].first;
        
        return ans;
        
        
        
    }
};
