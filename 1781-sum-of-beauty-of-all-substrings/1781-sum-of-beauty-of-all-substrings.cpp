class Solution {
public:
    int beautySum(string a) {
        
        int n = a.size(),ans=0,mx,mn;
        unordered_map<char,int> m;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                m[a[j]]++;
                mn= INT_MAX;
                mx = INT_MIN;
                for(auto k:m)
                {
                    mx = max(mx,k.second);
                    mn = min(mn,k.second);
                }
                ans += (mx-mn);
            }
            m.clear();
        }
        return ans;
        
    }
};