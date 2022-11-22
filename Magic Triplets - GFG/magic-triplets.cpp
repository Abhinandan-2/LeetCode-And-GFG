//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int countTriplets(vector<int> a){
	    
	    int n = a.size(),res=0,j,l,r,c=0;
	    vector<int> ans(n,0);
	    
	    for(int i=n-1;i>=0;i--){
	        c=0;
	        for(int j=i+1;j<n;j++){
	            if(a[j]>a[i]) c++;
	        }
	        ans[i] = c;
	    }
	    
	    for(int i=0;i<n;i++){
	        
	        for(int j=i+1;j<n;j++){
	            if(a[j]>a[i]) res += ans[j];
	        }
	        
	    }
	    return res;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends