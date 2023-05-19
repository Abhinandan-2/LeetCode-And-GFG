//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&r, int m, vector<int>q){
        sort(r.begin(),r.end());
        vector<pair<int,int>> x, y;
        vector<int> ans(m);
        pair<int,int> p;
        int st = r[0][0] , en = r[0][1], in;
        for(int i=1;i<n;i++){
            if(r[i][0]>en){
                x.push_back({st,en});
                st = r[i][0];
                en = r[i][1];
            }
            else en = max(en,r[i][1]);
        }
        x.push_back({st,en});
        st = 1;
        n = x.size();
        for(int i=0;i<n;i++){
            en = st + (x[i].second-x[i].first);
            y.push_back({st,en});
            st = en+1;
        }
        for(int i=0;i<m;i++){
            p = {q[i],INT_MAX};
            in = upper_bound(y.begin(),y.end(),p)-y.begin();
            in--;
            ans[i] = y[in].second<q[i] ? -1 : x[in].first + (q[i]-y[in].first);
        }
        return ans;
    } 
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends