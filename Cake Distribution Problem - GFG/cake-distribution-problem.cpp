//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    bool is(vector<int> &a,int k,long long m){
        long long sum =0 ;
        int count =0  , n =a.size();
        for(int i=0;i<n;i++){
            sum += a[i];
            if(sum>=m){
                count++;
                sum=0;
            }
            if(count>=k+1) return 1;
        }
        return 0;
    }
    int maxSweetness(vector<int>& a, int n, int k) {
        long long l = *min_element(a.begin(),a.end()) , h = 0 , m , ans ;
        for(auto &i:a) h+= i;
        while(l<=h){
            m = l+(h-l)/2;
            if(is(a,k,m)){
                ans = m;
                l = m+1;
            }
            else h = m-1;
        }
        return (int)ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends