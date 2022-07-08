// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    
    bool isnotValid(string &a)
    {
        unordered_map<char,int> m;
        for(int i=0;i<a.size();i++)
        {
            if(m.count(a[i]))
            return 1;
            m[a[i]]++;
        }
        return 0;
    }
    
    
public:
    int rank(string a){
        
        int n = a.size();
        
        if(isnotValid(a))
        return 0;
        
        set<char> s;
        
        for(int i=0;i<n;i++)
        s.insert(a[i]);
        
        vector<int> per(n,0);
        long long mul=1 ,mod = 1e6+3,ans =0,temp;
        for(int i=1;i<n;i++)
        {
            mul*= i;
            mul %= mod;
            per[i] = (int)mul;
        }
        int dis;
        for(int i=0;i<n;i++)
        {
            dis = distance(s.begin(),s.find(a[i]));
            s.erase(a[i]);
            temp = (long long)dis*per[n-i-1];
            ans += temp;
            ans %=mod;
        }
        
        ans++;
        ans %= mod;
        
        return (int)ans;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.rank(S)<<endl;
    }
    return 0;
}  // } Driver Code Ends