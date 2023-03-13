//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long maxPossibleValue(int n,vector<int> a, vector<int> b) {
        long long ans =0 ;
        int f = -1, s = -1 ,t = -1, m1 ,m2, m3 , val;
        for(int i=0;i<n;i++){
            if(b[i]>=2&&f==-1){
                f = a[i];
                b[i] -= 2;
            }
            if(b[i]>=2&&s==-1){
                s = a[i];
                b[i] -= 2;
            }
            if(b[i]>=2&&t==-1){
                t = a[i];
                b[i] -= 2;
            }
            val = (b[i]/4)*4;
            ans += (long long)val*a[i];
            b[i]-=val;
            if(f!=-1&&s!=-1&&t!=-1){
                m1 = max({f,s,t});
                m3 = min({f,s,t});
                m2 = f+s+t-m1-m3;
                ans += m1*2 + m2*2;
                f = m3;
                s = -1;
                t = -1;
            }
            if(b[i]>=2){
                if(f==-1) f = a[i];
                else if(s==-1) s= a[i];
                else t = a[i];
            }
            // cout<<ans<<" "<<f<<" "<<s<<" "<<t<<endl;
        }
        m1 = max({f,s,t});
        m3 = min({f,s,t});
        m2 = f+s+t-m1-m3;
        if(m1!=-1&&m2!=-1) ans += m1*2+m2*2;
        return ans;
        
    }
    
};


// 8
// 9 1 5 2 10 6 7 8
// 5 2 2 7 2 10 7 3





//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N), B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
          cin>>B[i];
        }
        Solution obj;
        auto ans = obj.maxPossibleValue(N,A,B);
        cout<<ans<<endl;
    }
} 
// } Driver Code Ends