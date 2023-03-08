//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

#define ll long long int

class Solution{
    public:
    
        bool is(vector<int> &a,int k,int w,ll m){
            
            int n = a.size(),en;
            vector<ll> v(n+1,0);
            ll diff, total;
            for(int i=0;i<n;i++){
                if(i!=0) v[i] +=v[i-1];
                total = v[i]+a[i];
                if(total<m){
                    diff = m-total;
                    if(diff>k) return 0;
                    k -= diff;
                    v[i] += diff;
                    en = min(n,i+w);
                    v[en] -= diff;
                }
            }
            return 1;
            
        }
    
        long long int maximizeMinHeight(int n,int k,int w,vector <int> &a){
            
            ll l = *min_element(a.begin(),a.end()) ,h = *max_element(a.begin(),a.end())+k , m , ans;
            while(l<=h){
                
                m = l+(h-l)/2;
                if(is(a,k,w,m)){
                    ans = m ;
                    l= m+1;
                }
                else h = m-1;
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
        int n,k,w;
        cin>>n>>k>>w;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        cout<<s.maximizeMinHeight(n,k,w,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends