// { Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string a[],int n)
    {
        unordered_map<string,int> m;
        for(int i=0;i<n;i++)
        m[a[i]]++;
        
        int mx =0;
        string ans;
        for(auto i:m)
        {
            if(i.second>=mx)
            {
                if(i.second==mx)
                {
                    ans= min(ans,i.first);
                }
                else
                {
                    mx = i.second;
                    ans = i.first;
                }
            }
        }
        
        return {ans,to_string(m[ans])};
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}
  // } Driver Code Ends