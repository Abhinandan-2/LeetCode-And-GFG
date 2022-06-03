// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    
    void call(int i,vector<int> a[],int n,int c,int d,vector<int> &v)
    {
        v[i] = 1;
        if(v[d]==1)
        return ;
        for(int j=0;j<a[i].size();j++)
        {
            if(v[a[i][j]]==-1&&(i!=c||a[i][j]!=d))
            call(a[i][j],a,n,c,d,v);
        }
        return ;
    }
    
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int n, vector<int> a[], int c, int d) 
    {
        vector<int> v(n,-1);
        call(c,a,n,c,d,v);
        if(v[d]==1)
        return 0;
        return 1;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends