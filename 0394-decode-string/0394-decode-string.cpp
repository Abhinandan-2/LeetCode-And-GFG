class Solution {
    string solve(string &a,int &i){
        int n = a.size(),h =0 ;
        string ans ="", k ="";
        while(i<n){
            if(a[i]>=48&&a[i]<=57) {h*=10;h+=(a[i]-48);}
            else if(a[i]==']') return ans;
            else if(a[i]=='['){
                i++;
                k = solve(a,i);
                while(h!=0) {ans += k;h--;}
                h=0;
            }
            else ans.push_back(a[i]);
            i++;
        }
        return ans;  
    }
public:
    string decodeString(string a) { 
        int i =0 ;
        return  solve(a,i);
    }
};