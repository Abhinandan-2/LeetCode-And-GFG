//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:

    int call(vector<int> &a,vector<int> &vis,int cur){
        int n = a.size();
        if(cur>=n||cur<0) return 1;
        if(vis[cur]!=0) return vis[cur];
        vis[cur] = 2;
        int res = call(a,vis,cur+a[cur]);
        if(res==1) vis[cur] = 1;
        else vis[cur] = -1;
        return vis[cur];
    }

    int goodStones(int n,vector<int> &a){
        vector<int> vis(n,0);
        int ans =0 ;
        for(int i=0;i<n;i++){
            if(vis[i]==0) call(a,vis,i);
            if(vis[i]==1) ans++;
        }
        return ans;
        
    }  
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends