//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string a){
		    int n= a.size();
		    vector<int> v(26,0);
		    queue<char> q;
		    char p;
		    for(int i=0;i<n;i++){
		        v[a[i]-'a']++;
		        if(v[a[i]-'a']==1) q.push(a[i]);
		        while(!q.empty()){
		            p = q.front();
		          //  cout<<p<<" "<<v[p-'a'];
		            if(v[p-'a']==1){
		                a[i] = p;
		                break;
		            }
		            q.pop();
		        }
		        if(q.empty()) a[i]='#';
		      //  cout<<endl;
		    }
		    return a;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends