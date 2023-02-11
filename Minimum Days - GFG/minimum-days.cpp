//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
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
    int getMinimumDays(int n,string a, vector<int> &per) {
        set<pair<int,int>> s;
        pair<int,int> p;
        int st = 0 , en=0 ;
        for(int i=1;i<n;i++){
            if(a[i]!=a[i-1]){
                if(st!=en) s.insert({st,en});
                st = i;
            }
            en = i;
        }
        if(st!=en) s.insert({st,en});
        if(s.size()==0) return 0;
        for(int i=0;i<n;i++){
            p = {per[i],INT_MAX};
            auto it = s.upper_bound(p);
            if(it!=s.begin()){
                it--;
                p = *it;
                if(per[i]>=p.first&&per[i]<=p.second){
                    s.erase(it);
                    if(per[i]-p.first>1) s.insert({p.first,per[i]-1});
                    if(p.second-per[i]>1) s.insert({per[i]+1,p.second});
                }
            }
            if(s.size()==0) return i+1;
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        string S;cin>>S;
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        int res = obj.getMinimumDays(N,S, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends