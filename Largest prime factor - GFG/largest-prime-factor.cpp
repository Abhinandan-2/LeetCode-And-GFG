//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int n){
        int ans =0 , sq = sqrt(n);
        for(int i=2;i<=sq;i++){
            while(n%i==0){
                n/=i;
                ans = i;
            }
        }
        if(n==1) return ans;
        return n;
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
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends