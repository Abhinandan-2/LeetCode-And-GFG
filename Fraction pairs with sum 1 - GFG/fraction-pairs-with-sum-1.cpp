//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int n, int num[], int den[])
    {
        int len,first,second,ans=0,gcd;
        unordered_map<int,vector<int>> m;
        for(int i=0;i<n;i++){
            gcd = __gcd(num[i],den[i]);
            m[den[i]/gcd].push_back(num[i]/gcd);
        }
        for(auto &i:m){
            vector<int> &v = i.second;
            sort(v.begin(),v.end());
            // cout<<i.first<<"-> ";
            // for(auto &k:v) cout<<k<<" ";
            // cout<<endl;
            len = v.size();
            for(int j=0;j<len;j++){
                first = lower_bound(v.begin()+j+1,v.end(),i.first-v[j])-v.begin();
                second = upper_bound(v.begin()+j+1,v.end(),i.first-v[j])-v.begin();
                // cout<<v[j]<<" " <<first<<" "<<second<<endl;
                ans += second-first;
            }
        }
        return ans;
        
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
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends