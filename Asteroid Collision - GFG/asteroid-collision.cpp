//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int n, vector<int> &a) {
        int f;
        stack<int> s,p;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(a[i]<0){
                f=0;
                while(!s.empty()&&s.top()<abs(a[i])) s.pop();
                if(!s.empty()&&s.top()==abs(a[i])){
                    s.pop();
                    f=1;
                }
                if(f==0&&s.empty()) ans.push_back(a[i]);
            }
            else s.push(a[i]);
        }
        while(!s.empty()){
            p.push(s.top());
            s.pop();
        }
        while(!p.empty()){
            ans.push_back(p.top());
            p.pop();
        }
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

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends