#define ll long long

class Solution {
public:
    long long maxAlternatingSum(vector<int>& a) {
        
        ll n= a.size() , f  =0, ans =0,l= a[0] ;
        ans = a[0];
        for(int i=1;i<n;i++)
        {
            if(a[i]==a[i-1])
                continue;
            if(f==0)
            {
                if(a[i]>a[i-1])
                {
                    ans-=l;
                    ans+= a[i];
                    l = a[i];
                }
                else
                {
                    ans -= a[i];
                    l =a[i];
                    f=1;
                } 
            }
            else
            {
                if(a[i]<a[i-1])
                {
                    ans += l;
                    ans -= a[i];
                    l = a[i];
                }
                else
                {
                    ans += a[i];
                    l = a[i];
                    f=0;
                }
            }
        }
        
        if(f==1)
            ans += l;
        return ans;
        
        
    }
};