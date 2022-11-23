//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	vector<int> LIS(vector<int> &a){
	    
	    int n = a.size();
	    vector<int> ans(n,1);
	    
	    for(int i=0;i<n;i++){
	        for(int j=i-1;j>=0;j--){
	            if(a[j]<a[i]){
	                
	                ans[i] = max(ans[i],ans[j]+1);
	                
	            }
	        }
	    }
	    return ans;
	    
	    
	}
	
	
	int LongestBitonicSequence(vector<int> a)
	{
	    
	    vector<int> first = LIS(a);
	    reverse(a.begin(),a.end());
	    vector<int> second = LIS(a);
	    reverse(second.begin(),second.end());
	    
	    int ans =0 ,n = a.size();
	    
	    for(int i=0;i<n;i++){
	        ans= max(ans,first[i]+second[i]-1);
	    }
	    
	    return ans;
	    
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
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends