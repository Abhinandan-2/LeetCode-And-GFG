class Solution {
public:
    int can_replace(string &s, string &t , int pos){
        for(int i=0;i<s.size();i++){
            if(t[i+pos]!='?' && t[i+pos]!=s[i])return 0;
        }
        return 1;
    }
    int replace(string &s, string &t , int pos){
        int replace=0;
        for(int i=0;i<s.size();i++){
            if(t[i+pos]!='?')t[i+pos]='?',replace++;
        }
        return replace;
    }
    vector<int> movesToStamp(string s, string t) {
        vector<int>res,vis(t.size(),0);
        int cnt=0;
        while(cnt!=t.size()){
            int change=0;
            for(int i=0;i<=t.size()-s.size();i++){
                if(vis[i]==0 && can_replace(s,t,i)){
                    cnt+=replace(s,t,i);
                    vis[i]=1;
                    change=1;
                    res.push_back(i);
                }
            }
            if(change==0)return {};
        }
        reverse(res.begin(),res.end());
        return res;
    }
};