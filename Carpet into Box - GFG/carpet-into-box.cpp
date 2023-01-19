//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int carpetBox(int A, int B, int C, int D){
        int a = A , b = B , first =0 ,second=0;
        while(a>C){
            a/=2;
            first++;
        }
        while(b>D){
            b/=2;
            first++;
        }
        a=A;
        b=B;
        while(a>D){
            a/=2;
            second++;
        }
        while(b>C){
            b/=2;
            second++;
        }
        return min(first,second);
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends