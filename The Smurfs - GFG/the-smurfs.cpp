//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findMin(int n, char a[]){
        
        int count =1 ,f=0;
        char cur = a[0];
        for(int i=1;i<n;i++) if(a[i]!=cur) { f=1 ; break;}
        if(f==0) return n;
        for(int i=1;i<n;i++){
            if(a[i]==cur) count++;
            else{
                if(count%2!=0){
                    if(a[i]=='R'){
                        if(cur=='B') cur= 'G';
                        else cur = 'B';
                    }
                    else if(a[i]=='G'){
                        if(cur=='B') cur = 'R';
                        else cur= 'B';
                    }
                    else{
                        if(cur=='R') cur = 'G';
                        else cur = 'R';
                    }
                }
                else cur = a[i];
                count =1;
            }
        }
        
        if(count%2==0) return 2;
        return 1;
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        cout<<ob.findMin(n, a)<<"\n";
    }
    return 0;
}
// } Driver Code Ends