//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int s, int d){
        // int pos;
        if(s==1||d==1) return "-1";
        vector<int> v(d);
        for(int i=0;i<d-1;i++){
            if(s==1) v[i] = 0;
            else if(s>9){
                v[i] = 9;
                s -= 9;
            }
            else{
                v[i] = s-1;
                s = 1;
            }
        }
        if(s>9) return "-1";
        v[d-1] = s;
        s = -1;
        for(int i=1;i<d;i++){
            if(v[i]<9){
                v[i]++;
                s = i;
                break;
            }
        }
        if(s==-1) return "-1";
        for(int i=s-1;i>=0;i--){
            if(v[i]>0){
                v[i]--;
                break;
            }
        }
        string ans ;
        for(int i=d-1;i>=0;i--) ans.push_back(v[i]+48);
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
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends