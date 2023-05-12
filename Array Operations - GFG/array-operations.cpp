//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &a) {
        int ans =0, f =0 ,g =0  ;
        for(int i=0;i<n;i++){
            if(a[i]!=0){
                if(f==0) f=1;
            }
            else{
                g = 1;
                if(f==1){
                    ans++;
                    f=0;
                }
            }
        }
        if(f==1) ans++;
        return g==0 ? -1 : ans;
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
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends