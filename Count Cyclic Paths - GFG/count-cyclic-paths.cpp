//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int countPaths(int n){
        vector<int> v, h(4);
        v= {1,0,0,0};
        long long k , mod = 1e9+7;
        for(int i=1;i<=n;i++){
            
            k = (long long)v[1]+v[2]+v[3];
            k %= mod;
            h[0] = (int)k;
            
            k = (long long)v[0]+v[2]+v[3];
            k %= mod;
            h[1] = (int)k;
            
            k = (long long)v[0]+v[1]+v[3];
            k %= mod;
            h[2] = (int)k;
            
            
            k = (long long)v[0]+v[1]+v[2];
            k %= mod;
            h[3] = (int)k;
            
            v = h;
            
        }
        return v[0];
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
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends