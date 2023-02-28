//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> optimalArray(int n,vector<int> &a){
        
        int i=1 , j =0 , res = 0 ;
        vector<int> ans(n);
        ans[0] = 0; 
        while(i<n){
            if(i%2!=0){
                res += (a[i]-a[j]);
            }
            else{
                j++;
                res += (a[i]-a[j]);
            }
            ans[i]=res;
            i++;
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
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Solution obj;
        vector<int> ans=obj.optimalArray(n,a);
        for(auto ele:ans){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends