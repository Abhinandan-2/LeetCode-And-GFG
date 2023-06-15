//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string a) {
        int n = a.size(), low , high , mx = 0;
        string ans;
        for(int i=0;i<n;i++){
            low = i;
            high = i;
            while(low>=0&&high<n&&a[low]==a[high]){
                low--;
                high++;
            }
            if(high-low-1>mx){
                mx = high-low-1;
                ans = a.substr(low+1,mx);
            }
            low = i;
            high = i+1;
             while(low>=0&&high<n&&a[low]==a[high]){
                low--;
                high++;
            }
            if(high-low-1>mx){
                mx = high-low-1;
                ans = a.substr(low+1,mx);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends