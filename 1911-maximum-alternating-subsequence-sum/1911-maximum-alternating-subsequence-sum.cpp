#define ll long long

class Solution {
public:
    long long maxAlternatingSum(vector<int>& a) {
        
        ll n= a.size() , flag  =0, ans =0,last = a[0] ;
        ans = a[0];
        for(int i=1;i<n;i++)
        {
            if(a[i]==a[i-1])
                continue;
            if(flag==0)
            {
                if(a[i]>last)
                {
                    ans-=last;
                    ans+= a[i];
                    last = a[i];
                }
                else
                {
                    ans -= a[i];
                    last=a[i];
                    flag=1;
                } 
            }
            else
            {
                if(a[i]<last)
                {
                    ans +=last;
                    ans -= a[i];
                    last = a[i];
                }
                else
                {
                    ans += a[i];
                    last = a[i];
                    flag=0;
                }
            }
        }
        
        if(flag==1)
            ans += last;
        return ans;
        
        
    }
};