//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:

    // static bool com(string &a,string &b){
        
    // }
    string longestString(vector<string> &a)
    {
        unordered_map<string,int> mp;
        // vector<string> can;
        string h;
        int  f;
        auto com = [&](string h,string k){
            if(h.size()>k.size()) return 1;
        else if(h.size()<k.size()) return 0;
        return h<k ? 1 : 0 ;
        };
        sort(a.begin(),a.end(),com);
        for(auto &i:a) mp[i]++;
        for(auto &i:a){
            f=0;
            for(auto &j:i){
                h += j;
                if(!mp.count(h)){
                    f=1;
                    break;
                }
            }
            if(f==0) return i;
            h.clear();
        }
        return "";
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends