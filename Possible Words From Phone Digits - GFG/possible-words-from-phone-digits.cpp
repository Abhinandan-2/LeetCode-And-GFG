// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    
    void call(int a[],string b,vector<string> &ans,int i,int n,unordered_map<int,string> &m)
    {
        if(i==n)
        {
            ans.push_back(b);
            return ;
        }
        
        for(int j=0;j<m[a[i]].size();j++)
        {
            b.push_back(m[a[i]][j]);
            call(a,b,ans,i+1,n,m);
            b.pop_back();
        }
        return ;
    }
    
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int n)
    {
        unordered_map<int,string> m;
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";
        
        vector<string> ans;
        string b;
        call(a,b,ans,0,n,m);
        return ans;
        
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends