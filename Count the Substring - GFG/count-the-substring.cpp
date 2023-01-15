//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
public:
  long long countSubstring(string a){
      long long ans =0 ;
      int sum =0 ,below =0 ;
      unordered_map<int,int> m;
      m[0]++;
      for(auto &i:a){
          if(i=='0'){
              sum--;
              below -= m[sum];
          }
          else{
              below += m[sum];
              sum++;
          }
          ans += below;
          m[sum]++;
      }
      return ans;
  }
};

//{ Driver Code Starts.
int main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
 int t=1;
 cin>>t;
 for(int i=1;i<=t;i++){
    string S;
    cin>>S;
    Solution obj;
    long long ans =obj.countSubstring(S);
    cout<<ans<<endl;
 }
}
// } Driver Code Ends