//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> a, int k) {
        unordered_map<int,int> m,v;
        for(auto i:a) m[i%k]++;
        v=m;
        for(auto i:m){
            // cout<<i.first<<" "<<i.second<<endl;
            if(i.first==0){
                if(i.second%2!=0) return 0;
            }
            else{
                if(k%2==0&&i.first==k/2){
                    if(i.second%2!=0) return 0;
                }
                else if (v[k-i.first]!=i.second) return 0;
            }
        }
        return 1;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends