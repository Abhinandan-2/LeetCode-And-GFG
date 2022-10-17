//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	void call(vector<vector<int>> &a,int i,int j,vector<int> &ans){
	    int n = a.size();
	    while(i<n&&j>=0) ans.push_back(a[i++][j--]);
	    return ;
	}
	public:
	vector<int> downwardDigonal(int n, vector<vector<int>> a){
		vector<int> ans;
		for(int i=0;i<n;i++) call(a,0,i,ans);
		for(int i=1;i<n;i++) call(a,i,n-1,ans);
		return ans;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends