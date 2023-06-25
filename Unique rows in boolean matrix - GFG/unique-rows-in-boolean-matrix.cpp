//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);


// } Driver Code Ends
class Solution
{
    public:
    // #define MAX 1000
    vector<vector<int>> uniqueRow(int a[MAX][MAX],int row,int col){
        unordered_map<long long,int> m;
        vector<vector<int>> ans;
        vector<int> h;
        long long num =0 ;
        for(int i=0;i<row;i++){
            num =0 ;
            for(int j=0;j<col;j++){
                num *= 2;
                if(a[i][j]==1) num++;
                h.push_back(a[i][j]);
            }
            if(!m.count(num)){
                ans.push_back(h);
                m[num]++;
            }
            h.clear();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	Solution ob;
    	vector<vector<int>> vec = ob.uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}

// } Driver Code Ends