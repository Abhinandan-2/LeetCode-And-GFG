//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ll long long


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	ll countSubarray(int a[], int n, int k) {
	    ll ans =0,c=0 ;
	    for(int i=0;i<n;i++){
	        ans += (n-i);
	        a[i]>k ? c=0 :c++;
	        ans -= c;
	    }
	    return ans;
	}
};


// 4 16
// 30 4 23 6



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.countSubarray(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends