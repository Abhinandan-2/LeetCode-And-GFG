//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    long long int distinctColoring(int n, int r[], int g[], int b[]){
        vector<long long int> f1(n),f2(n),f3(n);
        f1[n-1] = r[n-1];
        f2[n-1] = g[n-1];
        f3[n-1] = b[n-1];
        for(int i=n-2;i>=0;i--){
            f1[i] = min(f2[i+1],f3[i+1])+r[i];
            f2[i] = min(f1[i+1],f3[i+1])+g[i];
            f3[i] = min(f1[i+1],f2[i+1])+b[i];
        }
        return min({f1[0],f2[0],f3[0]});
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends