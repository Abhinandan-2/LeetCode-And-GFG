//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	long long int NoOfChicks(int n){
	    if(n==1) return 1;
	    vector<long long> v(n+1);
	    v[0] = 1;
	    v[1] = 1;
	    for(int i=2;i<=n;i++){
	        v[i] = 3*v[i-1];
	        if(i==6) v[i]-=1;
	        else if(i>6) v[i] -= (v[i-6]*2);
	    }
	    return v[n-1]*3;
	}
};

// 1 3 9 27 81 243(1) 726(2) 2172(6) 6498(18) 19440(19386)

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		long long int ans = obj.NoOfChicks(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends