class Solution {
    void makePermutation(string &a,int i,string &res,unordered_set<string> &ans){
        int n = a.size();
        if(i==n){ ans.insert(res);return ;}
        if(a[i]>=97&&a[i]<=122){
            res.push_back(a[i]);
            makePermutation(a,i+1,res,ans);
            res.pop_back();
            return ;
        }
        makePermutation(a,i+1,res,ans);
        res.push_back(a[i]);
        makePermutation(a,i+1,res,ans);
        res.pop_back();
        return ;
    }
    bool isValid(string &a){
        int s=0;
        for(auto i:a){
            if(i=='(') s++;
            else if(i==')'){
                if(s==0) return 0;
                s--;
            }
        }
        if(s!=0) return 0;
        return 1;
    }
public:
    vector<string> removeInvalidParentheses(string a) {
        int n = a.size(),mx=-1;
        unordered_set<string> sol;
        vector<string> ans,vec;
        string res;
        makePermutation(a,0,res,sol);
        for(auto i:sol) if(isValid(i)) ans.push_back(i);
        for(auto i:ans) mx = max(mx,(int)i.size());
        for(auto i:ans) if(i.size()==mx) vec.push_back(i);
        if(vec.size()==0) vec.push_back("");
        return vec; 
    }
};