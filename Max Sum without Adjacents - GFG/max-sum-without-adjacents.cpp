//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *a, int n) {
	    if(n==1) return a[0];
	    if(n==2) return max(a[0],a[1]);
	    a[2] += a[0];
	    for(int i=3;i<n;i++){
	        a[i] += max(a[i-2],a[i-3]);
	    }
	    return max(a[n-1],a[n-2]);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends