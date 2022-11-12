//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	
	    int findAns(string &a,char x,int k){
	        int ans = 0 ,i=0,j=0 , n = a.size() ;
	        while(i<n){
	            if(a[i]==x) i++;
	            else{
	                if(k!=0){
	                    i++;
	                    k--;
	                }
	                else{
	                    while(j<n&&a[j]==x) j++;
	                    j++;
	                    i++;
	                }
	            }
	            ans = max(ans,i-j);
	        }
	        
	        return ans;
	        
	        
	    }     
	   
		int characterReplacement(string a, int k){
		    int ans = 0 , res;
		    for(char i='A'; i<='Z';i++){
		        res = findAns(a,i,k);
		        ans = max(ans,res);
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends