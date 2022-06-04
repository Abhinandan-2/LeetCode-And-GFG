// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string nextPalin(string a) { 
        
        int n = a.size();
        if(n==1)
        return "-1";
        string ans = a.substr(0,n/2);
        
        int k = n/2;
        char mx=ans[k-1];
        int f=-1,g = k-1;
        for(int i=k-2;i>=0;i--)
        {
            if(ans[i]<mx)
            {
                f = i;
                break;
            }
            mx = a[i];
            g = i;
        }
        if(f==-1)
        return "-1";
        
        char p = ans[f];
        for(int i=f+1;i<k;i++)
        {
            if(ans[i]>p)
            {
                if(ans[i]<mx)
                {
                    mx = ans[i];
                    g= i;
                }
            }
        }
        
        swap(ans[f],ans[g]);
        sort(ans.begin()+f+1,ans.end());
        string res = ans;
        if(n%2!=0)
            ans.push_back(a[k]);
         
        reverse(res.begin(),res.end());
        ans += res;
        return ans;
        
        
        
        
        
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}  // } Driver Code Ends