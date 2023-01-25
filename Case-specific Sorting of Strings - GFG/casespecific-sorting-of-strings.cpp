//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string a, int n){
        string lower , upper;
        for(auto &i:a) isupper(i) ? upper.push_back(i) : lower.push_back(i);
        sort(upper.begin(),upper.end());
        sort(lower.begin(),lower.end());
        int i=0,j=0;
        for(auto &k:a) k = isupper(k) ? upper[i++] : lower[j++];
        return a;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends