class Solution {
public:
    int numSub(string a) {
        
        int n = a.size();
        int i=0,j=0,f=0;
        long long ans =0 ,mod =1e9+7;
        
        while(i<n)
        {
            if(a[i]=='1')
            {
                if(f==0)
                {
                    f=1;
                    j =i;
                }
                ans += (i-j+1);
            }
            else
            {
                f =0 ;
            }
            i++;
            ans %= mod;
        }
        return ans;
        
    }
};