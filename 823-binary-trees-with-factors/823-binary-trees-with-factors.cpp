class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& a) {
        
        int n = a.size();
        sort(a.begin(),a.end());
        unordered_map<int,int> m;
        for(auto i:a)
            m[i] = 1;
        long long ans =0 , mod=1e9+7,f,g,h,res=0,k;
        for(int i=0;i<n;i++)
        {
            h = a[i];
            res=0;
            for(int j=2;j<=sqrt(h);j++)
            {
                f=0;
                if(h%j==0)
                {
                    k = h/j;
                    if(m.count(j)&&m.count(k))
                    {
                        f= m[j];
                        g = m[k];
                        f *=g;
                        if(j!=k)
                            f*=2;
                    }
                }
                res += f;
            }
            res++;
            res %= mod;
            m[h] = res;
            ans += res;
            ans %= mod;
        }
        
        return ans;
        
        
        
    }
};