class Solution {
public:
    long long minimumDifference(vector<int>& a) {
        
        int n  = a.size();
        int m = n/3;
        long long sum1=0, sum2 = 0;
        priority_queue<int> q;
        for(int i=0;i<m;i++)
        {
            sum1 += a[i];
            q.push(a[i]);
        }
        vector<pair<int,int>> v,p;
        for(int i=m;i<n;i++)
        {
            v.push_back({a[i],i-m});
            p.push_back({a[i],0});
        }
        sort(v.begin(),v.end(),greater<pair<int,int>> ());
        for(int i=0;i<v.size();i++)
        {
            if(i<m)
                sum2 += v[i].first;
            p[v[i].second].second = i;
        }
        int k=m-1;
        long long ans = sum1-sum2;
        for(int i=0;i<m;i++)
        {
            q.push(p[i].first);
            sum1 += p[i].first;
            sum1 -= q.top();
            q.pop();
            if(p[i].second<=k)
            {
                sum2 -= p[i].first;
                k++;
                while(v[k].first==-1)
                    k++;
                sum2+=v[k].first;
            }
            else
                v[p[i].second].first = -1;
            ans = min(ans,sum1-sum2);
        }
        
        return ans;
        
    }
};