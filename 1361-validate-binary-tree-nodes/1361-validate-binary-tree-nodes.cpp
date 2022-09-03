class Solution {
    int find_set(int a,vector<int> &p){
        if(a==p[a]) return a;
        return p[a] = find_set(p[a],p);
    }
    void union_set(int x,int y,vector<int> &p,vector<int> &s){
        if(s[x]>s[y]) swap(x,y);
        p[x] = y; s[y] += s[x];
        return ;
    }
    bool check(vector<int> &a,vector<int> &in,vector<int> &p,vector<int> &s){
        for(int i=0;i<a.size();i++){
            if(a[i]==-1) continue;
            in[a[i]]++;
            int x = find_set(i,p) ,y = find_set(a[i],p);
            if(x==y) return 0;
            union_set(x,y,p,s);
        }
        return 1;
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& left, vector<int>& right) {
        int f=0,g;
        vector<int> in(n,0),p(n,0),s(n,0);
        for(int i=0;i<n;i++) p[i] = i;
        if(!check(left,in,p,s)||!check(right,in,p,s)) return 0;
        for(int i=0;i<n;i++) in[i]>1 ? f=2 : (in[i]==0 ? f++ : g=0);
        if(f!=1) return 0;
        return 1;
    }
};