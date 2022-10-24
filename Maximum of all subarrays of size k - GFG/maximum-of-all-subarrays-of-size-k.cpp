//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *a, int n, int k)
    {
        vector<int> ans;
        deque<int> q;
        for(int i=0;i<k;i++){
            while(!q.empty()&&a[q.back()]<=a[i])
            q.pop_back();
            q.push_back(i);
        }
        ans.push_back(a[q.front()]);
        for(int i=k;i<n;i++){
            if(q.front()<=i-k) q.pop_front();
            while(!q.empty()&&a[q.back()]<=a[i])
            q.pop_back();
            q.push_back(i);
            ans.push_back(a[q.front()]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends