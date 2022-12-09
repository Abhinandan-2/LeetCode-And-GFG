//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
long long numOfWays(int n, int m)
{
    long long ans = 0, total = n*m , c= 1, y1 ,x1, mod = 1e9+7;
    
    int x[] = {1,1,2,2,-1,-1,-2,-2};
    int y[] = {2,-2,1,-1,2,-2,1,-1};
    
    // queue<pair<int,int>> q;
    // pair<int,int> p;
    // q.push({0,0});
    
    // while(!q.empty()){
        
    //     sz = q.size();
        
        
    // }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            c=1;
            for(int k=0;k<8;k++){
                x1 = x[k]+i;
                y1 = y[k]+j;
                if(x1>=0&&x1<n&&y1>=0&&y1<m) c++;
            }
            ans += (total-c);
            ans %= mod;
        }
    }
    return ans;
    
}