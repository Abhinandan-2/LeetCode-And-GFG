//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    
    // static bool com(vector<int> a,vector<int> b){
    //     if(a[1]==b[1]) return a[0]<b[0];
    //     return a[1]<b[1];
    // }
        int largestArea(int n,int m,int k,vector<vector<int>> &a){
            if(k==0) return n*m;
            vector<int> p,q;
            for(auto i:a){
                p.push_back(i[0]);
                q.push_back(i[1]);
            }
            sort(p.begin(),p.end());
            int s = 0 , r = 0, c = 0;
            for(int i=0;i<k;i++){
                r = max(r,(p[i]-s-1));
                s = p[i];
            }
            r = max(r,n-s);
            sort(q.begin(),q.end());
            s = 0;
            for(int i=0;i<k;i++){
                c = max(c,(q[i]-s-1));
                s = q[i];
            }
            c = max(c,m-s);
            return r*c;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    }
    return 0;
}
// } Driver Code Ends