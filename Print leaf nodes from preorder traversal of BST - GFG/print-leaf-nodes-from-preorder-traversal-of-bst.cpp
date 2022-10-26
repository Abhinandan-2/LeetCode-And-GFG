//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leafNodes(int a[],int n) {
        int count;
        vector<int> ans;
        stack<pair<int,int>> s;
        pair<int,int> p;
        
        for(int i=0;i<n;i++){
            count =0;
                while(!s.empty()&&a[i]>s.top().first){
                    p = s.top();
                    s.pop();
                    if(p.second==0) ans.push_back(p.first);
                    count++;
                }
                if(!s.empty()){
                    p = s.top();
                    s.pop();
                    p.second=1;
                    s.push(p);
                }
                s.push({a[i],0});
                if(count==1) ans.pop_back();
                // k = s;
                // while(!k.empty()){
                //     p = k.top();
                //     k.pop();
                //     cout<<p.first<<" "<<p.second<<" ";
                // }
                // cout<<endl;
            
        }
        p = s.top();
        s.pop();
        ans.push_back(p.first);
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
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends