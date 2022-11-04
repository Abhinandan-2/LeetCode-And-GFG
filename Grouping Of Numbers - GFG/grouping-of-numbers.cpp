//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxGroupSize(int a[], int n, int k) {
        int h,d,ans=0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++) m[a[i]%k]++;
        for(int i=0;i<n;i++){
            h = a[i]%k;
            d = k-h;
            if(h==d||h==0){
                if(m.count(h)){
                    ans++;
                    m.erase(h);
                }
            }
            else{
                if(m[h]==m[d]){
                    ans++;
                    m[d]--;
                }
                else if(m[h]>m[d]) ans++;
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxGroupSize(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends