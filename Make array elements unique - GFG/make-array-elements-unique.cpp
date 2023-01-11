//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> a, int n) {
        int count =1 , extra =0 , gap ;
        long long int ans =0 ;
        sort(a.begin(),a.end());
        for(int i=1;i<n;i++){
            if(a[i]==a[i-1]) count++;
            else{
                extra += count-1;
                gap = a[i]-a[i-1]-1;
                ans += ((long long int)extra*(extra+1))/2;
                if(gap>=extra) extra =0 ;
                else{
                    ans -=  ((long long int)(extra-gap)*(extra-gap+1))/2;
                    extra -= gap;
                    ans += extra;
                } 
                count =1 ;
            }
        }
        extra += count-1;
        ans += ((long long int)extra*(extra+1))/2;
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends