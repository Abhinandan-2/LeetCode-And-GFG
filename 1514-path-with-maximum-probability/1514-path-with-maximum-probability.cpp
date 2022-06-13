class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& ed, vector<double>& s, int st, int en) {
        
        vector<vector<pair<int,double>>> a(n);
        for(int i=0;i<ed.size();i++)
        {
            // cout<<i;
            a[ed[i][0]].push_back({ed[i][1],s[i]});
            a[ed[i][1]].push_back({ed[i][0],s[i]});
        }
        // for(auto i:a)
        // {
        //     for(auto j:i)
        //         cout<<j.first<<" "<<j.second<<" ";
        //     cout<<endl;
        // }
        vector<int> v(n,-1);
        unordered_map<int,double> m;
        v[st] = 1;
        for(int j=0;j<a[st].size();j++)
            m[a[st][j].first] = a[st][j].second;
        double mx;
        int f;
        while(m.size()!=0)
        {
            mx = -1.0;
            for(auto i:m)
            {
                // cout<<i.first<<" "<<i.second<<endl;
                if(i.second>mx)
                {
                    mx = i.second;
                    f = i.first;
                }
            }
            // cout<<f<<" ";
            m.erase(f);
            v[f] = 1;
            if(f==en)
                return mx;
            for(int j=0;j<a[f].size();j++)
            {
                if(v[a[f][j].first]==-1)
                {
                    m[a[f][j].first] = max(m[a[f][j].first],mx*a[f][j].second);
                }
            }
        }
        
        return 0;
        
        
    }
};