//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string a) {
        int n = a.size();
        if(n<=3) return n;
        string first = a.substr(0,2) , second = a.substr(2,2);
        int i =2 ,j =4 ,in =-1;
        if(first==second) in = 2;
        while(j<n){
            first += a[i];
            i++;
            second.erase(second.begin());
            second += a[j];
            j++;
            if(j>=n) break;
            second += a[j];
            j++;
            if(first==second) in = i;
        }
        if(in==-1) return n;
        return n-in+1;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends