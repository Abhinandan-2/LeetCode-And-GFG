// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    void call(vector<vector<int>> &a,int i,int j,int &c,int x[],int y[])
    {
        int n = a.size() , m = a[0].size(),x1,y1;
        a[i][j] = 2;
        c++;
        for(int k=0;k<8;k++)
        {
            x1 = i+x[k];
            y1 = j+y[k];
            if(x1>=0&&x1<n&&y1>=0&&y1<m&&a[x1][y1]==1)
            {
                call(a,x1,y1,c,x,y);
            }
        }
        return ;
    }
    
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& a) {
        
        int n = a.size() , m = a[0].size();
        // vector<vector<int>> a(n,vector<int> (m));
        int x[] = {0,0,1,1,1,-1,-1,-1};
        int y[] = {1,-1,1,0,-1,1,0,-1};
        int c,ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==1)
                {
                    c=0;
                    call(a,i,j,c,x,y);
                    ans=max(ans,c);
                }
            }
        }
        
        return ans;
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends