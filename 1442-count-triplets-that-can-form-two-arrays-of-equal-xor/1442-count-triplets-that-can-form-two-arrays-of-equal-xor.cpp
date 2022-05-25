class Solution {
public:
    int countTriplets(vector<int>& a) {
        
        unordered_map<int,int> m,v;
        
        int ans =0, n = a.size(),k,h;
        vector<int> xr(n);
        xr[0] = a[0];
        for(int i=1;i<n;i++)
            xr[i] = a[i]^xr[i-1];
        
        for(auto i:xr)
            m[i]++;
        
        for(int j=1;j<n;j++)
        {
            h = a[j-1];
            for(auto it:m)
            {
                k = it.first^h;
                v[k] = it.second;
            }
            v[0]--;
            if(v[0]==0)
                v.erase(0);
            m = v;
            v.clear();
            k = xr[j-1];
            ans += m[k];
            for(int i=0;i<j-1;i++)
            {
                k ^= a[i];
                ans += m[k];
            }
            
        }
        return ans;
        
        
    }
};