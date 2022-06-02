// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.

string call(int n)
{
    string ans;
    while(n)
    {
        ans.push_back(n%2+48);
        n/=2;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

vector<string> generate(int n)
{
    vector<string> ans;
	for(int i=1;i<=n;i++)
	    ans.push_back(call(i));
	return ans;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends