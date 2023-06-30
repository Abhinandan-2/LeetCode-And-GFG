//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int isDivisible(string a){
	    int n = a.size() , num =0 ;
	    for(int i=0;i<n;i++){
	        num *=2 ;
	        if(a[i]=='1') num++;
	        num %= 3;
	    }
	    return num==0 ? 1 : 0;
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends