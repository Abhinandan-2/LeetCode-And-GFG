//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
    //Complete the function and return minimum number of operations
    public:
    int specialPalindrome(string a, string b){
        int n = a.size() , m = b.size() , res =0  , ans= INT_MAX ,h,x,y,h1,f=0;
        for(int i=0,j=n-1;i<j;i++,j--) if(a[i]!=a[j]) res++;
        for(int i=0;i<n-m+1;i++){
            y = n-1-i;
            x = i;
            h = res;
            f=0;
            // cout<<i<<"-> ";
            while(x<=i+m-1){
                if(y>=i&&y<=i+m-1){
                    h1 = x;
                    while(h1<=y){
                        if(a[h1]!=b[h1-i]) h++;
                        h1++;
                    }
                    while(x<=i+m-1&&y>=i&&y<=i+m-1){
                        if(x<y&&a[x]!=a[y]) h--;
                        if(b[x-i]!=b[y-i]){
                            f=1;
                            break;
                        }
                        // if(a[x]!=b[x-i]) h++;
                        // if(a[y]!=b[y-i]) h++;
                        x++;
                        y--;
                    }
                }
                else{
                    if(a[x]!=a[y]) h--;
                    if(b[x-i]!=a[y]) h++;
                    if(a[x]!=b[x-i]) h++;
                    x++;
                    y--;
                }
                if(f==1) break;
                
            }
            // cout<<endl;
            if(f==0){
                // cout<<h;
                ans = min(ans,h);
            }
            // cout<<endl;
            
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        Solution obj;
        int ans = obj.specialPalindrome(s1,s2);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends