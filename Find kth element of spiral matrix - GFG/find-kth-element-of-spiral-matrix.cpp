//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		int t =0 , d = n-1, l =0 , r = m-1, f=0;
 		while(l<=r&&t<=d){
 		    if(f==0) {
 		        for(int i=l;i<=r;i++){
 		            k--;
 		            if(k==0) return a[t][i];
 		        }
 		        t++;
 		    }
 		    else if(f==1){
 		        for(int i=t;i<=d;i++){
 		            k--;
 		            if(k==0) return a[i][r];
 		        }
 		        r--;
 		    }
 		    else if(f==2){
 		        for(int i=r;i>=l;i--){
 		            k--;
 		            if(k==0) return a[d][i];
 		        }
 		        d--;
 		    }
 		    else{
 		        for(int i=d;i>=t;i--){
 		            k--;
 		            if(k==0) return a[i][l];
 		        }
 		        l++;
 		    }
 		    f++;
 		    f %= 4;
 		}
 		return 0;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends