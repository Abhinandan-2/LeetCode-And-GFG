class Solution {
public:
    int movesToMakeZigzag(vector<int>& a) {
        
        int n = a.size(),ans=0,res=0 ,h;
        if(n==1)
            return 0;
        if(n==2)
        {
            if(a[0]==a[1])
                return 1;
            return 0;
        }
        for(int i=1;i<n;i+=2)
        {
            if(i==n-1)
            {
                if(a[i]>=a[i-1])
                    ans += (a[i]-a[i-1]+1);
            }
            else
            {
                h = min(a[i-1],a[i+1]);
                if(a[i]>=h)
                    ans+=(a[i]-h+1);
            }
            // cout<<ans<<" ";
        }
        for(int i=0;i<n;i+=2)
        {
            if(i==0)
            {
                if(a[i]>=a[i+1])
                    res += (a[i]-a[i+1]+1);
            }
            else if(i==n-1)
            {
                if(a[i]>=a[i-1])
                    res += (a[i]-a[i-1]+1);
            }
            else
            {
                h = min(a[i-1],a[i+1]);
                if(a[i]>=h)
                    res += (a[i]-h+1);
            }
        }
        // cout<<ans<<" "<<res;
        ans = min(ans,res);
        
        return ans;
        
    }
};