//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxEqualSum(int n,int m,int l,vector<int> &a,vector<int> &b,vector<int> &c){
        int sum1 = accumulate(a.begin(),a.end(),0) , sum2 = accumulate(b.begin(),b.end(),0) , sum3 = accumulate(c.begin(),c.end(),0) , i =0 , j =0 , k =0 , mxSum;
        while(i<n&&j<m&&k<l){
            if(sum1==sum2&&sum2==sum3) return sum1;
            mxSum = max({sum1,sum2,sum3});
            if(mxSum==sum1) sum1-= a[i++];
            else if(mxSum==sum2) sum2 -= b[j++];
            else sum3 -= c[k++];
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}
// } Driver Code Ends