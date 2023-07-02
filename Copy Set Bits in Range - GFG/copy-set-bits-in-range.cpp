//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        vector<int> v(31,0);
        int k =0,num=0 ;
        while(y){
            v[k++] = y%2;
            y/=2;
        }
        for(int i=0;i<31;i++) if(!(i>=l-1&&i<=r-1)) v[i] = 0;
        reverse(v.begin(),v.end());
        for(auto &i:v){
            num *= 2;
            if(i==1) num++;
        }
        x |= num;
        return x;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, l, r;
        cin>>x>>y>>l>>r;
        
        Solution ob;
        cout<<ob.setSetBit(x, y, l, r)<<"\n";
    }
    return 0;
}
// } Driver Code Ends