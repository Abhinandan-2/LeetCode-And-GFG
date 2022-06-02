// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &a, int t) {
        
        vector<vector<int>> ans;
        set<vector<int>> res;
        vector<int> c;
        int n = a.size(),h,k,l;
        
        sort(a.begin(),a.end());
        
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                h = t-a[i]-a[j];
                k = j+1;
                l = n-1;
                while(k<l)
                {
                    if(a[k]+a[l]==h)
                    {
                        c.push_back(a[i]);
                        c.push_back(a[j]);
                        c.push_back(a[k]);
                        c.push_back(a[l]);
                        res.insert(c);
                        c.clear();
                        k++;
                        l--;
                    }
                    else if(a[k]+a[l]>h)
                    l--;
                    else
                    k++;
                }
            }
        }
        
        for(auto i:res)
        ans.push_back(i);
        
        return ans;
        
        
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends