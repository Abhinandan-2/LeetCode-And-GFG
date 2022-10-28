//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string b[], string s)
    {
        int m = s.size();
        sort(b,b+n);
        vector<string> a;
        a.push_back(b[0]);
        for(int i=1;i<n;i++) if(b[i]!=b[i-1]) a.push_back(b[i]);
        n = a.size();
        vector<int> index,help;
        for(int i=0;i<n;i++) index.push_back(i);
        vector<vector<string>> ans;
        vector<string> res;
        for(int i=0;i<m;i++){
            for(auto j:index){
                if(a[j].size()>i){
                    if(a[j][i]==s[i]) help.push_back(j);
                }
            }
            if(help.size()==0) ans.push_back({"0"});
            else{
                for(auto j:help) res.push_back(a[j]);
                ans.push_back(res);
                res.clear();
            }
            index = help;
            help.clear();
        }
        return ans;
    }
};

// 2
// geekksgeeks geeksquiz
// gekaos


// 10
// abznehvggnuadsko abdnhtuydwvvh abqljekyiuvqajk abocnecsrlmnkp abhmtxfejjrhtldl abovqcafic abzqmnabyjprhuwqfnz abaclpshgwjnenlgdxtfa abpqjymhouwpswuelmntjy abpluvrsow
// aboikd


// 14
// sanabaaaaababa sanababaaaaaaaa sanaababba sanbbbbbaa sanabbbbaab sanaab sanaba sanaab sanaaabbabb sanabb sanaababbabaa sanbabb sanbabbbaabbbb sanaaaaabbb
// sanbbb

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends