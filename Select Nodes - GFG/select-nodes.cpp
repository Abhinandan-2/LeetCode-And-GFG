//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  
    int call(vector<vector<int>> &adj,int &ans,int cur,int pre){
        int f =0 ;
        for(auto &i:adj[cur]){
            if(i!=pre&&call(adj,ans,i,cur)==0){
                f=1;
            }
        }
        if(f==1) ans++;
        return f;
    }
    int countVertex(int n, vector<vector<int>>ed){
        vector<vector<int>> adj(n);
        for(auto &i:ed){
            adj[i[0]-1].push_back(i[1]-1);
            adj[i[1]-1].push_back(i[0]-1);
        }
        int ans =0 ;
        call(adj,ans,0,-1);
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends