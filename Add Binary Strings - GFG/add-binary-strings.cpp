//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string a, string b){
	    
	    int n = a.size() , m = b.size(),c=0,h;
	    
	    if(n<m){
	        swap(a,b);
	        swap(n,m);
	    }
	    reverse(a.begin(),a.end());
	    reverse(b.begin(),b.end());
	
	    for(int i=0;i<m;i++){
	        
	        h = a[i]-48+b[i]-48+c;
	        c = h/2;
	        a[i] = h%2+48;
	       // cout<<h<<" "<<c<<endl;
	    }
	    for(int i=m;i<n;i++){
	        h = a[i]+c-48;
	        c= h/2;
	        a[i] = h%2+48;
	       // cout<<h<<" "<<c<<endl;
	    }
	   // cout<<h<<" "<<c<<endl;
	    if(c){
	        a.push_back('1');
	    }
	    while(a.size()>0&&a.back()=='0') a.pop_back();
	    reverse(a.begin(),a.end());
	    return a;
	    
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends