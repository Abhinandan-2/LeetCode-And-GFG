class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        if(source==target)   // If source is target satation no need to use bus 
            return 0;
        unordered_map<int,vector<int>> stations;  /* store which buses travels that station

    Like for - routes = [[1,2,7],[3,6,7]]

    stations[1] = [0]
    stations[2] = [0]
    stations[7] = [0,1]
    stations[3] = [1]
    stations[6] = [1]
    
    */
    
        unordered_map<int,int> visitedBus,visitedStation;  // store which buses and stations are visited
        
        for(int i=0;i<routes.size();i++)        // Initializing the stations unordered_map as show above
            for(int j=0;j<routes[i].size();j++)
                stations[routes[i][j]].push_back(i);
        
        
        // Now it's time to BFS
        
        int ans =0 ,size, curBus ;
        queue<int> q;
       
        for(int i=0;i<stations[source].size();i++)   // store all buses in queue that travels source station
        {
            q.push(stations[source][i]);
            visitedBus[stations[source][i]]++;   // mark bus as visited
        }
        visitedStation[source]++;  // mark station as visited
        
        
        while(!q.empty())
        {
            size = q.size();   
            ans++;
            while(size--) // visit all station those will travels by all buses that are currently in queue (like we do in BFS)
            {
                curBus = q.front();
                q.pop();
                for(int i=0;i<routes[curBus].size();i++)
                {
                    if(routes[curBus][i]==target)  // If station is target station return the ans
                        return ans;
                    int &st = routes[curBus][i];  // Otherwise visit that station and store all buses that will travels that (st) station
                    if(!visitedStation.count(st))
                    {
                        for(int j=0;j<stations[st].size();j++)
                        {
                            if(!visitedBus.count(stations[st][j]))
                            {
                                q.push(stations[st][j]);
                                visitedBus[stations[st][j]]++;  // mark se visited
                            }
                        }
                        visitedStation[st]++;  // mark as visited
                    }
                }
            }
        }
        
        return -1;   // If target not found return -1
        
        
    }
};