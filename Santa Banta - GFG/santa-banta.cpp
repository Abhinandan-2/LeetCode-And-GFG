//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    vector<int> prime;
public:
    int find_set(int a,vector<int> &p){
        if(p[a]==a) return a;
        // int ans = find_set(p[a],p);
        // p[a] = ans;
        // return ans;
        return p[a] = find_set(p[a],p);
        // return 5;
    }
    
    void union_set(int x,int y,vector<int> &p,vector<int> &s){
        x = find_set(x,p);
        y = find_set(y,p);
        if(x!=y){
            if(s[x]>s[y]) swap(x,y);
            s[y] += s[x];
            p[x] = y;
        }
        return ;
    }
    
    void precompute(){
        int len = 1000000;
        vector<int> isPrime(len,0);
        for(int i=2;i<=1000;i++){
            if(isPrime[i]==0){
                for(int j=i*i;j<len;j+=i) isPrime[j] = 1;
            }
        }
        for(int i=2;i<len;i++) if(isPrime[i]==0) prime.push_back(i);
        // for(auto &i:prime) cout<<i<<" ";
        return;
    }
    
    int helpSanta(int n, int m, vector<vector<int>> &a){
        if(m==0) return -1;
        vector<int> p(n), s(n,1);
        int x, y, mx = 0 ,len = a.size();
        for(int i=0;i<n;i++) p[i] = i;
        // for(auto &i:a){
        //     for(auto &j:i) cout<<j<<" ";
        //     cout<<endl;
        // }
        for(int i=0;i<len;i++){
            // cout<<i<<"->";
            for(int j=0;j<a[i].size();j++){
                // cout<<a[i][j]<<" ";
                x = find_set(i-1,p);
                y = find_set(a[i][j]-1,p);
                if(x!=y) union_set(i-1,a[i][j]-1,p,s);
            }
            // cout<<endl;
        }
        for(auto &i:s) mx = max(mx,i);
        // cout<<mx;
        return prime[mx-1];
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