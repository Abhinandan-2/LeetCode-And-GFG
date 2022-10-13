//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends

class Solution{
    public:
    int maximizeSum(int a[], int n) 
    {
        int mx= -1;
        long long ans =0 ;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[a[i]]++;
            mx = max(mx,a[i]);
        }
        vector<int> v(mx+1,0);
        for(auto i:m) v[i.first] = i.second;
        ans += mx*v[mx];
        for(int i=mx-1;i>=0;i--){
            if(v[i+1]>v[i]) v[i]=0;
            else v[i] -= v[i+1];
            ans += i*v[i];
        }
        return (int)ans;
    }

};


//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends