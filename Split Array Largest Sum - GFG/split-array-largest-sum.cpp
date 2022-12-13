//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    bool is(int a[],int m,int k,int n){
        
        int c =0 ,sum =0 ;
        for(int i=0;i<n;i++){
            sum+=a[i];
            if(sum>m){
                sum = a[i];
                c++;
                if(c>k) return 0;
            }
            
        }
        c++;
        if(c>k) return 0;
        return 1;
        
    }
    
  
    int splitArray(int a[] ,int n, int k) {
        
        int h = accumulate(a,a+n,0) , l= *max_element(a,a+n), m , ans;
        
        while(l<=h){
            
            m = l+(h-l)/2;
            if(is(a,m,k,n)){
                h = m-1;
                ans= m;
            }
            else l = m+1;
        }
        
        return ans;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends