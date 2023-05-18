//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    void call(int x,int y,vector<vector<int>> &v,vector<vector<int>> &a,int n,int m,bool &ans){
        if(x<0||x>=n||y<0||y>=m||a[x][y]==0||v[x][y]==1) return;
        v[x][y] = 1;
        call(x+1,y,v,a,n,m,ans);
        call(x-1,y,v,a,n,m,ans);
        call(x,y+1,v,a,n,m,ans);
        call(x,y-1,v,a,n,m,ans);
        if(x==0||x==n-1||y==0||y==m-1) ans = false;
        return;
    }
    int closedIslands(vector<vector<int>>& a, int n, int m) {
        vector<vector<int>> v(n,vector<int> (m,0));
        int ans = 0 ;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]==0){
                    if(a[i][j]==0) v[i][j] = 1;
                    else{
                        bool res = true;
                        call(i,j,v,a,n,m,res);
                        if(res) ans++;
                    }
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends