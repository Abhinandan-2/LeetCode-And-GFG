//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& a){
      long long int zero = (long long int)n*n;
      vector<int> row(n+1,0) , col(n+1,0);
      int rSize =0 , cSize =0 ;
      vector<long long int> ans;
      for(int i=0;i<k;i++){
          if(row[a[i][0]]==0){
              zero = zero-n+cSize;
              row[a[i][0]] = 1;
              rSize++;
          }
          if(col[a[i][1]]==0){
              zero = zero-n+rSize;
              col[a[i][1]] = 1;
              cSize++;
          }
          ans.push_back(zero);
      }
      return ans;
  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends