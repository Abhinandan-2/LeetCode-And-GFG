//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int n, int k) {
        int last , h, f=0;
        deque<int> q;
        for(int i=1;i<=n;i++) q.push_back(i);
        while(!q.empty()){
            h = k;
            if(f==0){
                while(h--&&!q.empty()){
                    last = q.front();
                    q.pop_front();
                }
                f=1;
            }
            else{
                while(h--&&!q.empty()){
                    last = q.back();
                    q.pop_back();
                }
                f=0;
            }
        }
        return last;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends