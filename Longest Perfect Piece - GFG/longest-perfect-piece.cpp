//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestPerfectPiece(int a[], int n) {
        int ans = 0 ,mn,mx,i=0,j=0;
        multiset<int> s;
        while(i<n){
            s.insert(a[i]);
            mn = *s.begin();
            mx = *s.rbegin();
            while(mx-mn>1){
                s.erase(a[j]);
                j++;
                mn = *s.begin();
                mx = *s.rbegin(); 
            }
            ans= max(ans,i-j+1);
            i++;
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.longestPerfectPiece(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends