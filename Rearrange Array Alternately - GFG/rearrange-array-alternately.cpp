//{ Driver Code Starts
// C++ program to rearrange an array in minimum 
// maximum form 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    void rearrange(long long *a, int n) { 
    	long long num = 10e10+7;
    	int pos ,orgPos,mid = n/2;
    	for(int i=0;i<n;i++) a[i] = num*i+a[i];
    	for(int i=0;i<n;i++){
    	    orgPos = -1;
    	    while(i!=orgPos){
    	        pos = a[i]/num;
    	        if(pos<mid) orgPos = (2*(pos+1))-1;
    	        else{
    	            orgPos = n-(2*(pos-mid+1));
    	            if(n%2!=0) orgPos++;
    	        }
    	        swap(a[i],a[orgPos]);
    	    }
    	}
    	for(int i=0;i<n;i++) a[i] = a[i]%num;
    	return;
    }
};

//{ Driver Code Starts.

// Driver program to test above function 
int main() 
{
    int t;
    
    //testcases
    cin >> t;
    
    while(t--){
        
        //size of array
        int n;
        cin >> n;
        
        long long arr[n];
        
        //adding elements to the array
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        
        //calling rearrange() function
        ob.rearrange(arr, n);
        
        //printing the elements
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 

// } Driver Code Ends