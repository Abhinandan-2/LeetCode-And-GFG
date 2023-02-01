//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  
  int findCircle(vector<int> &a,int cur,vector<int> &vis){
      int n = a.size();
      vis[cur] = 0;
      if(a[cur]==-1){
          vis[cur] = 1;
           return -1;
      }
      if(vis[a[cur]]==1){
          vis[cur] = 1;
          return -1;
      }
      if(vis[a[cur]]==0){
          vis[cur] = 1;
          return a[cur];
      };
      int res = findCircle(a,a[cur],vis);
      vis[cur] = 1;
      return res;
  }
  
  long long cycleSum(vector<int> &a,int cur,int &in){
      if(cur==in) return 0;
      return cycleSum(a,a[cur],in)+cur;
  }
  
  long long largestSumCycle(int n, vector<int> a){
      
      vector<int> vis(n,-1);
      long long ans = -1 ,res ;
      int in;
      for(int i=0;i<n;i++){
          if(vis[i]==-1){
              in = findCircle(a,i,vis);
              if(in!=-1){
                  res = cycleSum(a,a[in],in);
                  ans = max(ans,res+in);
              }
          }
      }
      return ans;
      
  }
};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends