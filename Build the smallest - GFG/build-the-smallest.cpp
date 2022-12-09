//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string a, int k)
{
    string ans;
    
    int n = a.size(),i=0,j=0,len;
    
    
    while(i<n){
        
        if(k<=0){
            if(ans.size()!=0||a[i]!='0')
            ans.push_back(a[i]);
            i++;
        }
        
        else{
            if(a[i]=='0'){
                len = ans.size();
                if(len<=k){
                    ans.clear();
                    k-=len;
                    i++;
                }
                else{
                     if(a[i]<ans.back()){
                 ans.pop_back();
                 k--;
            }
            else{
                ans.push_back(a[i]);
                i++;
            }
            
                }
            }
            else{
        if(ans.size()==0){
            ans.push_back(a[i]);
            i++;
        }
        else{
            
            if(a[i]<ans.back()){
                 ans.pop_back();
                 k--;
            }
            else{
                ans.push_back(a[i]);
                i++;
            }
            
        }
            }
        }
        // cout<<i<<" "<<ans<<" "<<k<<endl;
    }
    
    while(ans.size()!=0&&k!=0){
        ans.pop_back();
        k--;
    }
    
    
    if(ans.size()==0) return "0";
    return ans;
    
}