#define ll long long

class Solution {
public:
    long long maxTaxiEarnings(int k, vector<vector<int>>& a) {
        
        int n = a.size();
        unordered_map<int,vector<pair<int,ll>>> m;
        ll h;
        for(int i=0;i<n;i++)
        {
            h = a[i][1]-(ll)a[i][0]+(ll)a[i][2];
            m[a[i][0]].push_back({a[i][1],h});
        }
        ll f,g,k1;
        vector<ll> dp(k+1);
        dp[k] = 0;
        for(int i=k-1;i>=0;i--)
        {
            if(m.count(i))
            {
                k1 =0;
                for(int j=0;j<m[i].size();j++)
                {
                    f = dp[m[i][j].first];
                    g = m[i][j].second;
                    k1 = max(k1,f+g);
                }
                dp[i] = max(k1,dp[i+1]);
            }
            else
                dp[i] = dp[i+1];
        }
        
        return dp[0];
        
    }
};