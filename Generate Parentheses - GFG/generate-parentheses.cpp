// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    
    
    void call(int open,int close,int n,string &b,vector<string> &ans)
    {
        if(open==n&&close==n)
        {
            ans.push_back(b);
            return ;
        }
        
        if(open==n)
        {
            b.push_back(')');
            call(open,close+1,n,b,ans);
            b.pop_back();
            return ;
        }
        
        if(open==close)
        {
            b.push_back('(');
            call(open+1,close,n,b,ans);
            b.pop_back();
            return ;
        }
        
        b.push_back('(');
        call(open+1,close,n,b,ans);
        b.pop_back();
        b.push_back(')');
        call(open,close+1,n,b,ans);
        b.pop_back();
        return ;
        
    }
    
    vector<string> AllParenthesis(int n) 
    {
        string b;
        vector<string> ans;
        call(0,0,n,b,ans);
        return ans;
        
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends