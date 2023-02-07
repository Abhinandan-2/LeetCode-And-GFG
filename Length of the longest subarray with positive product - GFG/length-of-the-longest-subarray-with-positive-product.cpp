//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &a,int n){
            a.push_back(0);
            n++;
           int ans = 0 , count =0 , st = 0, negEn = -1, negSt = -1 ,f= 0;
           for(int i=0;i<n;i++){
               if(a[i]==0){
                   if(f==1) ans = count%2==0 ? max(ans,i-st) : max({ans,negEn-st,i-negSt-1});
                   count =0 ;
                   f = 0 ;
                   negSt = -1;
               }
               else{
                   if(f==0){
                       f=1;
                       st = i;
                   }
                   if(a[i]<0){
                       count++;
                       if(negSt==-1) negSt = i;
                       negEn = i;
                   }
               }
           }
           return ans;
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends