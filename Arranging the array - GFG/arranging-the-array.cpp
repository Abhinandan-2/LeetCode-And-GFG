//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution
{
    public:
        void merge(int a[],int st,int m,int en){
            int len = en-st+1;
            int t[len];
            int i=st, j= m+1, k =0 ;
            while(i<=m){
                if(a[i]>=0) break;
                t[k++] = a[i++];
            }
            while(j<=en){
                if(a[j]>=0) break;
                t[k++] = a[j++];
            }
            while(i<=m) t[k++] = a[i++];
            while(j<=en) t[k++] = a[j++];
            k=0;
            for(int i=st;i<=en;i++) a[i] = t[k++];
            return ;
        }
        
        void divideAndCon(int a[],int st,int en){
            if(st==en) return ;
            int m = st+(en-st)/2;
            divideAndCon(a,st,m);
            divideAndCon(a,m+1,en);
            merge(a,st,m,en);
            return ;
        }
        void Rearrange(int a[], int n){
            divideAndCon(a,0,n-1);
            return ;
        }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends