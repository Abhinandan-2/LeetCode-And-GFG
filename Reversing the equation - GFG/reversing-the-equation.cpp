//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string a)
        {
            reverse(a.begin(),a.end());
            int n = a.size(), f =0 ,st = -1;
            for(int i=0;i<n;i++){
                if(a[i]>='0'&&a[i]<='9'){
                    if(f==0){
                        st = i;
                        f =1;
                    }
                }
                else{
                    f =0 ;
                    reverse(a.begin()+st,a.begin()+i);
                }
            }
            if(f==1) reverse(a.begin()+st,a.end());
            return a;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends