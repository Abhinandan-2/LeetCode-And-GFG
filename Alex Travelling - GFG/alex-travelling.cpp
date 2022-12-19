//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int source) {
        vector<vector<pair<int,int>>> adj(n);
        vector<int> dis(n,INT_MAX);
        set<pair<int,int>> s;
        pair<int,int> p;
        for(int i=0;i<flights.size();i++) adj[flights[i][0]-1].push_back({flights[i][1]-1,flights[i][2]});
        source--;
        dis[source] = 0;
        s.insert({0,source});
        while(!s.empty()){
            p = *s.begin();
            s.erase(s.begin());
            for(int j=0;j<adj[p.second].size();j++){
                if(dis[adj[p.second][j].first]>p.first+adj[p.second][j].second){
                    s.erase({dis[adj[p.second][j].first],adj[p.second][j].first});
                    dis[adj[p.second][j].first] = p.first+adj[p.second][j].second;
                    s.insert({dis[adj[p.second][j].first],adj[p.second][j].first});
                }
            }
        }
        int mx = INT_MIN;
        for(int i=0;i<n;i++){
            if(dis[i]==INT_MAX) return -1;
            mx = max(mx,dis[i]);
        }
        return mx;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends