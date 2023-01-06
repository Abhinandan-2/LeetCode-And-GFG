//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
  
    int give(vector<int> &p){
        int ans =0 ;
        for(int i=3;i>=0;i--){
            ans *= 10;
            ans += p[i];
        }
        return ans;
    }
    
    bool isPrime(int &n){
        for(int i=2;i<=sqrt(n);i++) if(n%i==0) return 0;
        return 1;
    }
    
    int shortestPath(int x,int y){  
        if(x==y) return 0;
        int ans =0 ,p,num,sz;
        vector<int> v;
        unordered_map<int,int> m;
        queue<int> q;
        q.push(x);
        m[x]++;
        while(!q.empty()){
            ans++;
            sz = q.size();
            while(sz--){
                p = q.front();
                q.pop();
                // cout<<p<<" ";
                while(p){
                    v.push_back(p%10);
                    p/=10;
                }
                for(int i=0;i<4;i++){
                    p = v[i];
                    for(int j=0;j<10;j++){
                        if(i!=0||j!=0){
                            v[i] = j;
                            num = give(v);
                            if(num == y) return ans;
                            if(!m.count(num)&&isPrime(num)){
                                q.push(num);
                                m[num]++;
                            }
                        }
                    }
                    v[i] = p;
                }
                v.clear();
            }
            // cout<<endl;
        }
        return -1;
    }
};


//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    Solution obj;
    while(t--)
    {
        int Num1,Num2;
        cin>>Num1>>Num2;
        int answer=obj.shortestPath(Num1,Num2);
        cout<<answer<<endl;
    }
}
// } Driver Code Ends