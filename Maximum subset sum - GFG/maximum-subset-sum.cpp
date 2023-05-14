//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {

  public:
    long long findMaxSubsetSum(int n, vector<int> &a) {
        vector<long long> ans(n+1,0);
        ans[1] = a[0];
        for(int i=2;i<=n;i++) ans[i] = max(ans[i-1],ans[i-2])+a[i-1];
        return max(ans[n],ans[n-1]);
    }
    
    /*
    
    long long findMaxSubsetSum(int n, vector<int> &a) {
        long long sum =0 , i = 0 ;
        if(n==1){
            if(a[0]>=0) return a[0];
            return 0;
        }
        if(a[0]<0&&a[1]<0) i = a[0]>=a[1] ? 0 :  1;
        else if(a[0]<0) i = 1;
        while(i<n){
            sum += a[i];
            if(i+1<n&&a[i]>=0) i++;
            else if(i+2<n&&)
        }
        return 0;
    }
    
    */
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends