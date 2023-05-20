//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int n, int k, vector<int> &a) {
        if(n%k!=0) return 0;
        unordered_map<int,int> m;
        for(auto &i:a) m[i]++;
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++){
            if(m[a[i]]!=0){
                for(int j=a[i];j<a[i]+k;j++){
                    if(m[j]==0) return 0;
                    m[j]--;
                }
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends