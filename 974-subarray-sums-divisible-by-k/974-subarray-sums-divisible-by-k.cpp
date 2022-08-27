class Solution {
public:
    int subarraysDivByK(vector<int>& a, int k) {
        
        int n = a.size();
        a[0] %= k;
        a[0] += k;
        a[0] %= k;
        for(int i=1;i<n;i++)
        {
            a[i] += a[i-1];
            a[i] %= k;
            a[i] += k;
            a[i] %= k;
        }
        // for(auto i:a)
        //     cout<<i<<" ";
        unordered_map<int,int> m;
        m[0] = 1;
        
        int ans =0 ;
        
        for(int i=0;i<n;i++)
        {
            ans += m[a[i]];
            m[a[i]]++;
        }
        
        return ans;
        
    }
};