//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string allNeg(string &a,unordered_map<char,int> &m){
          int n = a.size(),mx =INT_MIN;
          char c ;
          string ans;
          for(int i=0;i<n;i++){
              if(m[a[i]]>0) return "-1";
              if(m[a[i]]==0){
                  ans += a[i];
                  return ans;
              }
              if(m[a[i]]>mx){
                  mx = m[a[i]];
                  c = a[i];
              }
          }
          ans += c;
          return ans;
      } 
      string maxSum(string a,char x[], int y[],int n){
          
          int sz = a.size(),f=0 ,g;
          unordered_map<char,int> m;
          for(auto i:a) m[i] = (int)i;
          for(int i=0;i<n;i++) m[x[i]] = y[i];
          string ans = allNeg(a,m);
          if(ans!="-1") return ans;
          int sum =0 , st = -1, len = 0 ,mx =0,ansst, anslen ;
          for(int i=0;i<sz;i++){
              sum += m[a[i]];
              if(sum<0){
                  sum =0;
                  st =-1;
                  len =0 ;
                  g=0;
                  f=0;
              }
              if(g!=0){
              if(f==0){
                st = i;
                len = 1;
                f=1;
              }
              else len++;  
                if(sum>mx){
                    mx= sum;
                    ansst = st;
                    anslen = len;
                }
              }
              else g=1;
              
          }
          ans = a.substr(ansst,anslen);
          return ans;
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends