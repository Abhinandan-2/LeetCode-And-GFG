// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:


    bool call(vector<vector<char>> &a,int i,int j,int p,int x[],int y[],string &b)
    {
        int n = a.size() , m=a[0].size() ,x1, y1;
        int m1 = b.size();
        if(p==m1)
        return 1;
        
        char c = a[i][j];
        a[i][j] = '.';
        bool ans;
        for(int k=0;k<4;k++)
        {
            x1 = i+x[k];
            y1 = j+y[k];
            if(x1>=0&&x1<n&&y1>=0&&y1<m&&a[x1][y1]==b[p])
            {
                ans = call(a,x1,y1,p+1,x,y,b);
                if(ans)
                return ans;
            }
        }
        a[i][j]  =c ;
        return false;
        
        
    }

    bool isWordExist(vector<vector<char>>& a, string b) {
        
        int n = a.size() , m = a[0].size();
        int x[] = {0,0,-1,1};
        int y[] = {1,-1,0,0};
        bool ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==b[0])
                {
                    ans = call(a,i,j,1,x,y,b);
                    if(ans)
                    return ans;
                }
            }
        }
        
        return false;
        
        
        // Code here
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends