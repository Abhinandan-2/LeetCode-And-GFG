//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    void addInAns(int i,int j,vector<int> &a,vector<vector<int>> &v,int &ans){
        if(i<0||i>9) return;
        int val = a[j];
        if(i>val) return ;
        if(j==0){
            ans+=1;
            return;
        }
        if(i<val){
            ans += v[i][j];
            return ;
        }
        addInAns(i-1,j-1,a,v,ans);
        addInAns(i+1,j-1,a,v,ans);
        return ;
    }
    int count(int n,vector<vector<int>> &v){
        int ans =0;
        if(n<10) return n+1;
        vector<int> a;
        while(n){
            a.push_back(n%10);
            n/=10;
        }
        int digit = a.size();
        for(int j=0;j<=digit-2;j++){
            for(int i=1;i<10;i++){
                ans += v[i][j];
            }
        }
        ans++;
        int first = a[digit-1];
        for(int i=1;i<first;i++){
            ans += v[i][digit-1];
        }
        int i= first , j = digit -1 ;
        addInAns(i,j,a,v,ans);
        return ans;
    }
    
    int steppingNumbers(int n, int m)
    {
        int digit = 0 ,h =m;
        while(h){
            digit++;
            h/=10;
        }
        vector<vector<int>> v(10,vector<int>(digit+1,1));
        for(int j=1;j<=digit;j++){
            for(int i=0;i<10;i++){
                if(i==0) v[i][j] = v[i+1][j-1];
                else if(i==9) v[i][j] = v[i-1][j-1];
                else v[i][j] = v[i-1][j-1]+v[i+1][j-1];
            }
        }
        
        int res = count(n-1,v);
        int ans = count(m,v);
        ans -= res;
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}


// } Driver Code Ends