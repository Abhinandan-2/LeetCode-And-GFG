//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool makePalindrome(int n,vector<string> &a){
        unordered_map<string,int> m;
        string h;
        for(auto &i:a) m[i]++;
        for(int i=0;i<n;i++){
            h = a[i];
            reverse(h.begin(),h.end());
            if(a[i]==h){
                if(m[h]>=2) m[h]-=2;
                if(m[h]==0) m.erase(h);
            }
            else if(m.count(a[i])&&m.count(h)){
                m[a[i]]--;
                if(m[a[i]]==0) m.erase(a[i]);
                m[h]--;
                if(m[h]==0) m.erase(h);
            }
        }
        if(m.size()>1) return 0;
        if(m.size()==0) return 1;
        if(m.begin()->second>1) return 0;
        h = m.begin()->first;
        n = h.size();
        for(int i=0,j=n-1;i<j;i++,j--) if(h[i]!=h[j]) return 0;
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
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends