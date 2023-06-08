//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
         k--;
        string ans ;
        map<int,int> m;
        for(int i=1;i<=n;i++)
        {
            m[i]++;
        }
        int fac =1;
        for(int i=n-1;i>0;i--)
        {
            fac *= i;
        }
        int d ,f,j;
        
        while(n--)
        {
            d = k/fac;
            d++;
            j=1;
            for(auto i:m)
            {
                if(j==d)
                {
                    f = i.first;
                    break;
                }
                j++;
            }
            m.erase(f);
            ans.push_back(f+48);
            k %= fac;
            if(n)
            fac /= n;
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends