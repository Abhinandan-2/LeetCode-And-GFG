//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {

  public:

  

    void solve(int node,vector<int>&dis,vector<int>&low,vector<bool>&vis,int par,vector<int>adj[],int &timer,vector<int>&art){

        

        vis[node]=true;

        

        dis[node]=low[node]=timer++;

        

        int child=0;

        

        for(auto &x:adj[node]){

            

            if(x==par) 

                continue;

                

            if(vis[x]==false){

                

              solve(x,dis,low,vis,node,adj,timer,art);

              

              low[node]=min(low[node],low[x]);

              

              if(low[x]>=dis[node] && par!=-1){

                  

                  art[node]=1;

                  

                }

                child++;

            }

            else{

                

                low[node]=min(low[node],dis[x]);

            }

        }

        if(par==-1 && child>1){

          art[node]=1;

        }    

    }

    

    

    vector<int> articulationPoints(int V, vector<int>adj[]){

        

        vector<int>dis(V,-1);

        

        vector<int>low(V,-1);

        

        vector<bool>vis(V,0);

        

        int timer=0;

        

        vector<int>art(V,0);

        

        solve(0,dis,low,vis,-1,adj,timer,art);

        

        vector<int>ans;

        

        for(int i=0;i<V;i++){

            if(art[i]==1){

                ans.push_back(i);

            }

        }

        if(ans.size()==0) ans.push_back(-1);

        return ans;

    }

};



//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends