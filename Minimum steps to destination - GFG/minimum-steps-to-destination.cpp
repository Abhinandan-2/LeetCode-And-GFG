// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minSteps(int n){
        
        int count =0, cur =0,jump=0 ;
        while(cur<n)
        {
            jump++;
            cur += jump;
            
        }
        
        if(n==cur)
        return jump;
        if((cur-n)%2==0)
        return jump;
        if(jump%2==0)
        return jump+1;
        return jump+2;
        
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int D;
        cin>>D;
        
        Solution ob;
        cout<<ob.minSteps(D)<<"\n";
    }
    return 0;
}  // } Driver Code Ends