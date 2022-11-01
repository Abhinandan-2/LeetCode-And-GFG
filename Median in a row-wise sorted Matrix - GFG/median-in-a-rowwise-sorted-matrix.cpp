//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &a, int n, int m){
        int l = INT_MAX, h = INT_MIN,mid,low, high ,help,tar = (n*m)/2,ans,f=0,res=INT_MAX,res1 = INT_MIN;
        for(auto i:a) for(auto j:i){
            l = min(l,j);
            h = max(h,j);
        }
        while(l<h){
            mid = l+(h-l)/2;
            low =0 ;
            high =0 ;
            for(int i=0;i<n;i++){
                low += lower_bound(a[i].begin(),a[i].end(),mid)-a[i].begin();
                help = upper_bound(a[i].begin(),a[i].end(),mid)-a[i].begin();
                high += (m-help);
            }
            if(low==tar&&high==tar) return mid;
            else if(low<tar&&high<tar) return mid;
            if(low==tar) {ans = mid; f=1 ; break;}
            else if(high==tar) {ans = mid;f=2;break;}
            if(high>tar) l = mid+1;
            else h = mid-1;
        }
        if(f==0) {ans = l; f=1;}
        for(auto i:a) for(auto j:i){
            if(j>=ans) res = min(j,res);
            if(j<=ans) res1 = max(j,res1);
        }
        if(f==1) return res;
        return res1;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends