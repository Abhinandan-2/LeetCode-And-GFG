class Solution {
public:
    int maxPerformance(int n, vector<int>& a, vector<int>& b, int k) {
        vector<pair<int,int>> help;
        for(int i=0;i<n;i++) help.push_back({b[i],a[i]});
        sort(help.begin(),help.end(),greater<pair<int,int>> ());
        priority_queue<int,vector<int>,greater<int>> q;
        long long sum =0,ans =0 ,mod=1e9+7;
        for(int i=0;i<n;i++)
        {
            sum += help[i].second;
            q.push(help[i].second);
            if(q.size()>k) {sum -= q.top(); q.pop();}
            ans = max(ans,sum*help[i].first);
        }
        return ans%mod;
    }
};