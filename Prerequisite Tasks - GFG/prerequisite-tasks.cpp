// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isPossible(int n, vector<pair<int, int> >& ed) {
	    
	    vector<vector<int>> a(n);
	    vector<int> in(n,0);
	    for(int i=0;i<ed.size();i++)
	    {
	        a[ed[i].second].push_back(ed[i].first);
	        //cout<<ed[i].first<<" ";
	        in[ed[i].first]++;
	    }
	    
	    queue<int> q;
	    int ans =0,p,h;
	    for(int i=0;i<n;i++)
	    {
	        //cout<<in[i]<<" ";
	        if(in[i]==0)
	        q.push(i);
	    }
	    
	    while(!q.empty())
	    {
	        p= q.front();
	        q.pop();
	        ans++;
	        h  =a[p].size();
	        for(int j=0;j<h;j++)
	        {
	            in[a[p][j]]--;
	            if(in[a[p][j]]==0)
	            q.push(a[p][j]);
	        }
	    }
	    //cout<<ans;
	    
	    if(ans==n)
	    return 1;
	    return 0;
	    
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends