//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int n,int k,vector<int> &a){
        vector<int> mn(n);
        mn[n-1] = a[n-1];
        for(int i=n-2;i>=0;i--) mn[i] = min(mn[i+1],a[i]);
        int ans =0 , mx = a[0];
        for(int i=0;i<n-1;i++){
            if(mx+mn[i+1]>=k) ans++;
            mx = max(mx,a[i+1]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends