//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int a[], int n) {
        int h;
        vector<int> lis;
        for(int i=0;i<n;i++){
            h = lower_bound(lis.begin(),lis.end(),a[i])-lis.begin();
            if(h==lis.size()) lis.push_back(a[i]);
            else lis[h] = a[i];
        }
        return n-lis.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends