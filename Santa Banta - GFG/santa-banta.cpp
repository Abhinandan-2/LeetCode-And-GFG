//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    vector<int> prime;
public:
    int find_set(int a,vector<int> &p){
        if(p[a]==a) return a;
        return p[a] = find_set(p[a],p);
    }
    void precompute(){
        vector<int> isPrime(1e6,0);
        for(int i=2;i<=1e3;i++) if(isPrime[i]==0) for(int j=i*i;j<1e6;j+=i) isPrime[j] = 1;
        for(int i=2;i<1e6;i++) if(isPrime[i]==0) prime.push_back(i);
        return;
    }
    int helpSanta(int n, int m, vector<vector<int>> &a){
        vector<int> p(n), s(n,1);
        int x, y, mx = 0 ,len = a.size();
        for(int i=0;i<n;i++) p[i] = i;
        for(int i=0;i<len;i++){
            for(int j=0;j<a[i].size();j++){
                x = find_set(i-1,p);
                y = find_set(a[i][j]-1,p);
                if(x!=y){
                    if(s[x]>s[y]) swap(x,y);
                    s[y] += s[x];
                    p[x] = y;
                }
            }
        }
        for(auto &i:s) mx = max(mx,i);
        return mx==1 ? -1 : prime[mx-1];
    }
};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g(n+10);
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends