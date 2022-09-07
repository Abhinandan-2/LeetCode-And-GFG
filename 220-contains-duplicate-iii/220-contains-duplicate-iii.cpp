class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& a, int k, int t) {
        
        if(k==0)
            return 0;
        multiset<int> s;
        int n = a.size(),h;
        for(int i=0;i<min(k+1,n);i++)
        {
            s.insert(a[i]);
        }
        long long ll;
        multiset<int>::iterator it;
        for(auto it=s.begin();it!=s.end();it++)
        {
            auto ij = it;
            ij++;
            if(ij!=s.end()){
            ll = abs((long long)(*it)-(long long)(*ij));
            if(ll<=(long long)t)
                return 1;
            }
        }
        
        for(int i=k+1;i<n;i++)
        {
            h = a[i-k-1];
            auto it = s.find(h);
            s.erase(it);
            auto ij = s.lower_bound(a[i]);
            if(ij==s.end())
            {
                ij--;
                h = *ij;
                ll = abs((long long)(h)-(long long)(a[i]));
                if(ll<=(long long)t)
                    return 1;
                s.insert(a[i]);
                continue;
            }
            h = *ij;
            ll = abs((long long)(h)-(long long)(a[i]));
            if(ll<=(long long)t)
                return 1;
            if(ij!=s.begin())
            {
                ij--;
                h = *ij;
                ll = abs((long long)(h)-(long long)(a[i]));
                if(ll<=(long long)t)
                    return 1;
            }
            s.insert(a[i]);  
        }
        
        return 0;
        
    }
};