//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool isValid(vector<vector<int>> &a,long long  int sum,long long int ex){
        int  n = a.size();
        long long int h;
        for(int i=0;i<n;i++){
            h=0;
            for(int j=0;j<n;j++){
                if(a[i][j]==0) h+= ex;
                h+=a[i][j];
            }
            if(h!=sum) return 0;
        }
        for(int j=0;j<n;j++){
            h=0;
            for(int i=0;i<n;i++){
                if(a[i][j]==0) h+= ex;
                h+= a[i][j];
            }
            if(h!=sum) return 0;
        }
        int i=0,j=0;
        h=0;
        while(i<n){
            if(a[i][j]==0) h+= ex;
            h+=a[i][j];
            i++;
            j++;
        }
        if(h!=sum) return 0;
        i=0;
        j =n-1;
        h=0;
        while(i<n){
            if(a[i][j]==0) h+= ex;
            h += a[i][j];
            i++;
            j--;
        }
        if(h!=sum) return 0;
        return 1;
        
    }
    long long int MissingNo(vector<vector<int> >& a) {
        
        int n = a.size(),x=-1,y=-1;
        long long int sum=0,d=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]==0){
                    x=i;
                    y=j;
                    break;
                }
            }
            if(x!=-1) break;
        }
        
        for(int i=0;i<n;i++){
            if(x==0) sum+=a[1][i];
            else sum += a[0][i];
            d += a[x][i];
        }
        if(sum-d>0&&isValid(a,sum,sum-d)) return sum-d;
        return -1;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		long long int ans = ob.MissingNo(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends