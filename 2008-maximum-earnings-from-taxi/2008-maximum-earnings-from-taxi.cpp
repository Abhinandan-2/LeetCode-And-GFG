#define ll long long

class Solution {
public:
    long long maxTaxiEarnings(int t, vector<vector<int>>& a) {
        
        int n = a.size();
        sort(a.begin(),a.end());
        vector<ll> dp(n) ;
        vector<int> b(n);
        for(int i=0;i<n;i++)
            b[i] = a[i][0];
        
        dp[n-1] = (ll)a[n-1][1]-(ll)a[n-1][0]+a[n-1][2];
        ll h,k,f,g,m;
        for(int i=n-2;i>=0;i--)
        {
            h = a[i][1];
            m = lower_bound(b.begin(),b.end(),h)-b.begin();
            k = a[i][1]-a[i][0]+a[i][2];
            f=0;
            if(m!=n)
            f = dp[m];
            g = dp[i+1];
            dp[i] = max(g,k+f);
        }
        return dp[0];
        
        
    }
};