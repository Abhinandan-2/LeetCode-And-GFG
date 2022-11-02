//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int removals(vector<int>& a, int k){
        int n = a.size(),ans = INT_MAX,h,in;
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++){
            h = a[i]+k;
            in = upper_bound(a.begin(),a.end(),h)-a.begin();
            h = n-(in-i);
            ans = min(ans,h);
            // cout<<in<<" " <<h<<" ";
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
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends