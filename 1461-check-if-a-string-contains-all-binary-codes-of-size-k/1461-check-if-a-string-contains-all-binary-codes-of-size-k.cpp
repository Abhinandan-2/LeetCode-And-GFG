class Solution {
public:
    bool hasAllCodes(string a, int k) {
        
        int n = a.size();
        unordered_map<int,int> m;
        if(k>=n)
            return 0;
        int res =0,pw = pow(2,k);
        for(int i=0;i<k;i++)
        {
            res *= 2;
            if(a[i]=='1')
                res++;
        }
        m[res]++;
        for(int i=k;i<n;i++)
        {
            res *= 2;
            if(a[i]=='1')
                res++;
            if(a[i-k]=='1')
                res -= pw;
            m[res]++;
        }
        if(m.size()==pw)
            return 1;
        return 0;
        
    }
};