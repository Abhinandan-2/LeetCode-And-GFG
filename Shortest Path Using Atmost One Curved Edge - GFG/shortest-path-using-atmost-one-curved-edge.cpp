//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    vector<int> dijsktra(int source,vector<vector<pair<int,int>>> &adj){
        
        int n = adj.size();
        vector<int> ans(n,INT_MAX);
        ans[source] = 0;
        set<pair<int,int>> s;
        pair<int,int> p;
        s.insert({0,source});
        while(!s.empty()){
            p = *s.begin();
            s.erase(s.begin());
            for(auto &i:adj[p.second]){
                if(ans[i.first]>p.first+i.second){
                    s.erase({ans[i.first],i.first});
                    ans[i.first] = p.first+i.second;
                    s.insert({p.first+i.second,i.first});
                }
            }
        }
        
        return ans;
        
        
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        // pair<int,int> p;
        // ans[s] = 0;
        // for(auto &i:adj[s]) q.push({i.second,i.first});
        // while(!q.empty()){
        //     p = q.top();
        //     q.pop();
        //     if(ans[p.second]>p.first){
        //         ans[p.second] = p.first;
        //         for(auto &i:adj[p.second]) q.push({i.second+p.first,i.first});
        //     }
        // }
        // return ans;
    }
  
    int shortestPath(int n, int m, int a, int b, vector<vector<int>> &ed) {
        
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &i:ed){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        
        vector<int> disA, disB ;
        disA = dijsktra(a,adj);
        disB = dijsktra(b,adj);
        
        int ans = disA[b];
        for(auto &i:ed){
            if(disA[i[0]]!=INT_MAX&&disB[i[1]]!=INT_MAX) ans = min(ans,disA[i[0]]+disB[i[1]]+i[3]);
            if(disA[i[1]]!=INT_MAX&&disB[i[0]]!=INT_MAX) ans = min(ans,disA[i[1]]+disB[i[0]]+i[3]);
        }
        
        if(ans==INT_MAX) return -1;
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,a,b;
        cin>>n>>m;
        cin>>a>>b;
        
        vector<vector<int>> edges;
        
        for(int i=0; i<m; i++)
        {
            int u,v,x,y;
            cin>>u>>v>>x>>y;
            edges.push_back({u,v,x,y});
        }

        Solution ob;
        cout << ob.shortestPath(n,m,a,b,edges) << endl;
    }
    return 0;
}
// } Driver Code Ends