class Solution {
    bool isValid(string &a,string &b,int x,int y,int n){
        int i = (x+1)%n, j =(y+1)%n;
        while(i!=x){
            if(a[i++]!=b[j++]) return 0;
            i %= n; j %= n;
        }
        return 1; 
    }
public:
    bool rotateString(string a, string b) {
        int n = a.size() , ms = b.size(),mn = INT_MAX,pos;
        if(n!=ms) return 0;
        unordered_map<char,int> m,v;
        for(auto i:a) m[i]++;
        for(auto i:b) v[i]++;
        if(m!=v) return 0;
        char c;
        for(auto i:m) if(mn>i.second){mn = i.second;c = i.first;}
        for(int i=0;i<n;i++) if(a[i]==c){ pos = i;break;}
        for(int i=0;i<n;i++) if(b[i]==c&&isValid(a,b,pos,i,n)) return 1;
        return 0;
    }
};