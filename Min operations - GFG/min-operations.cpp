//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int a, int b) {
        int ca = 0 , cb =0 ;
        while(a&&b){
            if(a%2==0&&b%2!=0) cb++;
            else if(a%2!=0&&b%2==0) ca++;
            a/=2;
            b/=2;
        }
        while(a){
            ca++;
            a/=2;
        }
        while(b){
            cb++;
            b/=2;
        }
        if(ca) ca=1;
        if(cb) cb=1;
        return ca+cb;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int a;
        scanf("%d",&a);
        
        
        int b;
        scanf("%d",&b);
        
        Solution obj;
        int res = obj.solve(a, b);
        
        printf("%d\n", res);
        
    }
}

// } Driver Code Ends