//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string a){
        int n = a.size(), pos = n;
        if(n>1&&a[1]==a[0]) pos = 1;
        else for(int i=1;i<n;i++) if(a[i]>a[i-1]){
            pos = i;
            break;
        }
        string ans = a.substr(0,pos);
        ans += ans;
        reverse(ans.begin()+pos,ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends