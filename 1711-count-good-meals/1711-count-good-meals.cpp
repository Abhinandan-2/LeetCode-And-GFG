class Solution {
public:
    int countPairs(vector<int>& a) {
        
        int n = a.size()  ,c1 ,c2 ,h, k,p ;
        long long ans =0, mod = 1e9+7;
        
        sort(a.begin(),a.end());
        
        for(int i=0;i<n-1;i++)
        {
            if(a[i]!=0)
            p = log2(a[i])/log2(2);
            else
            p=0;
            
            for(int j=p;j<=21;j++)
            {
                h = pow(2,j);
                k = h-a[i];
                if(k>=0)
                {
                    c1 = lower_bound(a.begin()+i+1,a.end(),k)-a.begin();
                    c2 = upper_bound(a.begin()+i+1,a.end(),k)-a.begin();
                    ans += (c2-c1);
                    ans %=mod;
                }
            }
        }
        
        return (int)ans;
        
        
        
    }
};