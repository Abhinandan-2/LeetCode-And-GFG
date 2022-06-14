// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
# define mod 1000000007

 // } Driver Code Ends
class Solution{
    
    long long call(int n,int p)
    {
        if(p==1)
        return (long long)n;
        
        long long h =1,k ,f;
        if(p%2!=0)
        {
            h = (long long)n;
            p--;
        }
        f = (long long)n*n;
        f %= (long long)mod;
        k = call((int)f,p/2);
        k %= (long long)mod;
        k *= h;
        k %= (long long)mod;
        return k;
        
    }
    
    public:
    //You need to complete this fucntion
    
    long long power(int n,int p)
    {
       long long ans = call(n,p);
       return ans;
        
    }

};

// { Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}  // } Driver Code Ends