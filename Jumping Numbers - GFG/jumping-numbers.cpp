//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool call(vector<int> &v,vector<int> &a,int i,int f){
        int n = v.size();
        bool h;
        if(i==n) return true;
        if(f==1){
            if(i==1){
                if(a[0]==0) a[i] = 9;
                else if(a[i-1]==9) a[i] =8;
                else a[i] = a[i-1]+1;
            }
            else{
                if(a[i-1]==9) a[i] = 8;
                else a[i] = a[i-1]+1;
            }
            call(v,a,i+1,f);
            return 1;
        }
        if(a[i-1]-1>v[i]) return 0;
        if(a[i-1]+1<v[i]){
            a[i] = a[i-1]+1;
            call(v,a,i+1,1);
            return 1;
        }
        else if(a[i-1]+1==v[i]){
            a[i] = a[i-1]+1;
            h = call(v,a,i+1,0);
            if(h) return 1;
        }
        if(a[i-1]==0) return 0;
        a[i] = a[i-1]-1;
        if(a[i]==v[i]){
            h = call(v,a,i+1,0);
            return h;
        }
        
        call(v,a,i+1,1);
        
        return 1;
        
    }
    
  
    long long jumpingNums(long long n) {
        if(n<=10) return n;
        vector<int> v,a;
        while(n){
            v.push_back(n%10);
            n/=10;
        }
        
        reverse(v.begin(),v.end());
        n = v.size();
        a.resize(n,0);
        a[0] = v[0];
        bool b = call(v,a,1,0);
        long long ans =0 ;
        if(b){
            for(int i=0;i<a.size();i++){
                ans *= 10;
                ans += a[i];
            }
            return ans;
        }
        a[0] = v[0]-1;
        call(v,a,1,1);
        for(int i=0;i<a.size();i++){
            ans *= 10;
            ans += a[i];
        }
        return ans;
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}
// } Driver Code Ends