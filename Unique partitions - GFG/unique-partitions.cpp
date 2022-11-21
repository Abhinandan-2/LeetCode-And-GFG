//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
	
	void call(int n,vector<vector<int>> &ans,vector<int> &b){
	    
	    if(n==0) ans.push_back(b);
	    
	    int last;
	    if(b.size()==0) last = INT_MAX;
	    else last = b.back();
	    
	    for(int i=min(last,n);i>0;i--){
	        b.push_back(i);
	        call(n-i,ans,b);
	        b.pop_back();
	    }
	    
	    return;
	    
	}
	
    vector<vector<int>> UniquePartitions(int n) {
        
        vector<vector<int>> ans;
        vector<int> b;
        
    
        
        call(n,ans,b);
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
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends