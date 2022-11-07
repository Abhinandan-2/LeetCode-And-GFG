//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

#define ll long long int

class Solution{
    public:
    vector<long long int> twoOddNum(long long int a[], long long int n)  
    {
        ll x =0 ,ans =0 ,res =0 , oneOddBit ;
        
        
        for(int i=0;i<n;i++) x^=a[i];
        
        oneOddBit = x& (~(x-1));
        
        
        for(int i=0;i<n;i++){
            if((a[i]&oneOddBit)!=0){
                ans ^= a[i];
            }
        }
        
        res = x^ans;
        
        if(ans>res) return {ans,res};
        return {res,ans};
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends