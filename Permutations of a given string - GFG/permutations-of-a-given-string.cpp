//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    void call(string &a,string &b,vector<int> &v,set<string> &res){
	        int n = a.size();
	        if(b.size()==n){
	            res.insert(b);
	            return ;
	        }
	        for(int i=0;i<n;i++) if(v[i]==0){
	            v[i]= 1;
	            b.push_back(a[i]);
	            call(a,b,v,res);
	            b.pop_back();
	            v[i] = 0;
	        }
	        return ;
	    }
		vector<string>find_permutation(string a){
		    int n= a.size();
		    vector<int> v(n,0);
		    string b;
		    set<string> res;
		    vector<string> ans;
		    call(a,b,v,res);
		    for(auto &i:res) ans.push_back(i);
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends