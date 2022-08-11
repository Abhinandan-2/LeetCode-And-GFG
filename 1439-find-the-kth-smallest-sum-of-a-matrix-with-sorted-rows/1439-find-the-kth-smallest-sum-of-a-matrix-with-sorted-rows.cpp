class Solution {
public:
    int kthSmallest(vector<vector<int>>& a, int t) {
        
        int n = a.size() , m = a[0].size();
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
        map<vector<int>,int> mp;
        vector<int> h;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            h.push_back(0);
            sum+=a[i][0];
        }
        h.insert(h.begin(),sum);
        mp[h]++;
        q.push(h);
        t--;
        while(t--)
        {
            h = q.top();
            q.pop();
            // for(auto i:h)
            //     cout<<i<<" ";
            // cout<<endl;
            for(int i=1;i<=n;i++)
            {
                if(h[i]!=m-1)
                {
                    h[i]++;
                    // cout<<i<<" "<<h[i]<<" ";
                    h[0] += (a[i-1][h[i]]-a[i-1][h[i]-1]);
            //         for(auto i:h)
            //     cout<<i<<" ";
            // cout<<endl;
                    if(!mp.count(h))
                    {
                        q.push(h);
                        mp[h]++;
                    }
                    h[0] -= (a[i-1][h[i]]-a[i-1][h[i]-1]);
                    h[i]--;
                //      for(auto i:h)
                // cout<<i<<" ";
            // cout<<endl;
                }
                
            }
        }
        h = q.top();
        return h[0];
    }
};