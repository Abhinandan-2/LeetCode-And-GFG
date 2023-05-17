//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string a){
        int len = a.size(), rowMn = 0 , rowMx =0 , colMn =0 , colMx =0 , rowCur =0 , colCur =0, width, hight;
        for(int i=0;i<len;i++){
            if(a[i]=='L') colCur--;
            else if(a[i]=='R') colCur++;
            else if(a[i]=='U') rowCur++;
            else rowCur--;
            colMn = min(colMn,colCur);
            colMx = max(colMx,colCur);
            rowMn = min(rowMn,rowCur);
            rowMx = max(rowMx,rowCur);
        }
        width = abs(colMn-colMx)+1;
        hight = abs(rowMn-rowMx)+1;
        if(n>=hight&&m>=width) return 1;
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends