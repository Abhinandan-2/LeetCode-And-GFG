class Solution {
public:
    void call(vector<string> &a,int i,int &ans,unordered_map<char,int> &m){
        int n = a.size();
        if(i>=n){
            int sz = m.size();
            ans = max(ans,sz);
            return ;
        }
        call(a,i+1,ans,m);
        unordered_map<char,int> v;
        for(int j=0;j<a[i].size();j++){
            if(v.count(a[i][j])) return ;
            v[a[i][j]]++;
        }
        for(int j=0;j<a[i].size();j++) if(m.count(a[i][j])) return ;
        for(int j=0;j<a[i].size();j++) m[a[i][j]]++;
        call(a,i+1,ans,m);
        for(int j=0;j<a[i].size();j++) m.erase(a[i][j]);
        return ;
    }
    int maxLength(vector<string>& a) {
        int ans =0 ;
        unordered_map<char,int> m;
        call(a,0,ans,m);
        return ans;
    }
};