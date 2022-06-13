class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& ed, vector<double>& s, int st, int en) {
        
        vector<vector<pair<int,double>>> a(n);
        for(int i=0;i<ed.size();i++)
        {
            a[ed[i][0]].push_back({ed[i][1],s[i]});
            a[ed[i][1]].push_back({ed[i][0],s[i]});
        }
        // for(auto i:a)
        // {
        //     for(auto j:i)
        //         cout<<j.first<<" "<<j.second<<" ";
        //     cout<<endl;
        // }
        vector<double> dis(n,-1);
        set<pair<double,int>> m;
        pair<double,int> p;
        dis[st] = 0.0;
        m.insert({0.0,st});
        int node,u;
        double d,curdis,temp;
        while(!m.empty())
        {
            auto it = m.end();
            it--;
            p = *it;
            m.erase(it);
            node = p.second;
            // cout<<node<<" ";
            d = p.first;
            if(node==en)
                return d;
            for(int j=0;j<a[node].size();j++)
            {
                u = a[node][j].first;
                curdis = a[node][j].second;
                if(d==0.0)
                    temp = curdis;
                else if(curdis==0.0)
                    temp = d;
                else
                    temp = d*curdis;
                if(dis[u]<temp)
                {
                    m.erase({dis[u],u});
                    dis[u] = temp;
                    m.insert({dis[u],u});
                }
            }
        }
        
        return 0;
        
        
    }
};