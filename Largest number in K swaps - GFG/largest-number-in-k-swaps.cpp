// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    
    void call(string a,int t,string &ans,int i)
    {
        // cout<<a<<" "<<i<<endl;
        int n = a.size();
        if(i>=n||t==0)
        {
            // cout<<a<<" "<<i<<endl;
            ans= max(ans,a); 
            // cout<<a<<" "<<i<<" "<<ans<<endl;
            return ;
        }
        
        vector<int> v;
        char ch = a[i];
        v.push_back(i);
        for(int j=i+1;j<n;j++)
        {
            if(a[j]>=ch)
            {
                if(a[j]>ch)
                v.clear();
                ch =a[j];
                v.push_back(j);
            }
        }
        
        if(i!=v[0])
        {
            for(int j=0;j<v.size();j++)
            {
                swap(a[i],a[v[j]]);
                call(a,t-1,ans,i+1);
                swap(a[i],a[v[j]]);
            }
        }
        else
        call(a,t,ans,i+1);
        
        return ;
        
    }
    
    public:
    //Function to find the largest number after k swaps.
    string findMaximumNum(string a, int t)
    {
        
        int n = a.size();
        string ans;
        call(a,t,ans,0);
        
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        // int n = a.size();
        // vector<int> v;
        // int k=0,f;
        // char ch;
        // for(int i=0;i<n;i++)
        // {
        //     if(k==t)
        //     break;
        //     ch = 47;
        //     f =-1;
        //     // cout<<a[i]<<" ";
        //     for(int j=i;j<n;j++)
        //     {
        //         if(a[j]>=ch)
        //         {
        //             if(a[j]>ch)
        //             v.clear();
        //             ch = a[j];
        //             v.push_back(j);
        //         }
        //     }
        //     // cout<<a[i]<<" "<<ch<<" "<<f<<" ";
        //     if(a[i]!=v[0])
        //     {
        //         for(int i)
        //     }
            
        //     // if(k==t)
        //     // break;
        //     // p = q.top();
        //     // q.pop();
        //     // cout<<a[i]<<" "<<p.first<<" "<<p.second<<endl;
        //     // if(p.first!=a[i])
        //     // {
        //     //     cout<<a[i]<<" "<<p.first<<" "<<p.second<<" ";
        //     //     swap(a[i],a[p.second]);
        //     //     k++;
        //     // }
        //     // cout<<a<<endl;
        // }
        // return a;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends