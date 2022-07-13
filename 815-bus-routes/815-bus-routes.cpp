class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        if(source==target)
            return 0;
        unordered_map<int,vector<int>> stations;
        unordered_map<int,int> bus,station;
        
        for(int i=0;i<routes.size();i++)
        {
            for(int j=0;j<routes[i].size();j++)
            {
                stations[routes[i][j]].push_back(i);
            }
        }
        
        // for(auto i:stations)
        // {
        //     cout<<i.first<<" ";
        //     for(auto j:i.second)
        //     {
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        
        int ans =0 ,h,p;
        queue<int> q;
        if(!station.count(source)){
        station[source]++;
        for(int i=0;i<stations[source].size();i++)
        {
            if(!bus.count(stations[source][i])){
            q.push(stations[source][i]);
            bus[stations[source][i]]++;
            }
        }
        }
        
        while(!q.empty())
        {
            h = q.size();
            ans++;
            while(h--)
            {
                p = q.front();
                q.pop();
                // cout<<p<<" ";
                for(int i=0;i<routes[p].size();i++)
                {
                    if(routes[p][i]==target)
                        return ans;
                    int &st = routes[p][i];
                    if(!station.count(st))
                    {
                        station[st]++;
                        for(int j=0;j<stations[st].size();j++)
                        {
                            if(!bus.count(stations[st][j]))
                            {
                                q.push(stations[st][j]);
                                bus[stations[st][j]]++;
                            }
                        }
                    }
                }
            }
        }
        
        return -1;
        
        
    }
};