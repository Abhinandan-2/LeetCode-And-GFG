// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        string ans;
        while(n)
        {
            if(n%26==0)
            {
                ans.push_back('Z');
                n /=26;
                n--;
            }
            else
            {
                ans.push_back(n%26+'A'-1);
                n/=26;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}
  // } Driver Code Ends