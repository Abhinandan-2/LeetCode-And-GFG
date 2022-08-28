class Solution {
public:
    int numberOfSets(int n, int k) {
        
        vector<int> v(n,0) , h(n,1);
        long long t , mod= 1e9+7;
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<n;j++)
            {
                t = (long long)v[j-1]*2+h[j-1];
                if(j!=1)
                    t -= v[j-2];
                t += mod;
                t %= mod;
                v[j] = (int)t;
            }
            // for(auto i:v)
            //     cout<<i<<" ";
            // cout<<endl;
            h = v;
        }
        
        return v[n-1];
        
    }
};