//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> ed[], int s)
    {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<ed[i].size();j++){
                adj[i].push_back({ed[i][j][0],ed[i][j][1]});
            }
        }
        // int n = adj.size();
        vector<int> ans(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        pair<int,int> p;
        ans[s] = 0;
        for(auto &i:adj[s]) q.push({i.second,i.first});
        while(!q.empty()){
            p = q.top();
            q.pop();
            if(ans[p.second]>p.first){
                ans[p.second] = p.first;
                for(auto &i:adj[p.second]) q.push({i.second+p.first,i.first});
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends