class Solution {
    int find_set(int a,vector<int> &p){
        if(a==p[a]) return a;
        return p[a] = find_set(p[a],p);
    }
    void union_set(int x,int y,vector<int> &p,vector<int> &s){
        x = find_set(x,p);
        y = find_set(y,p);
        if(x!=y){
            if(s[x]>s[y]) swap(x,y);
            p[x] = y;
            s[y] += s[y];
        }
        return ;
    }
public:
    bool equationsPossible(vector<string>& a) {
        int n =a.size(),x,y,h,k;
        vector<int> p(26,0),s(26,0);
        for(int i=0;i<26;i++) p[i] = i;
        for(int i=0;i<n;i++) if(a[i][1]=='=') union_set((int)a[i][0]-97,(int)a[i][3]-97,p,s);
        for(int i=0;i<n;i++){
            x = find_set((int)a[i][0]-97,p);
            y = find_set((int)a[i][3]-97,p);
            if(a[i][1]=='!'&&x==y) return 0;
        }
        return 1;
    }
};