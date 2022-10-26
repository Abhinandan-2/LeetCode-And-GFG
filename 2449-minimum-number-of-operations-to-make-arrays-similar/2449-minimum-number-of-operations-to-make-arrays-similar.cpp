class Solution {
public:
    static bool com(int x,int y){
        if((x%2==0&&y%2==0)||(x%2!=0&&y%2!=0)) return x<y;
        if(x%2!=0) return 1;
        return 0;
    }
    long long makeSimilar(vector<int>& a, vector<int>& b) {
        int n = a.size();
        sort(a.begin(),a.end(),com);
        sort(b.begin(),b.end(),com);
        long long ans =0 ;
        for(int i=0;i<n;i++) if(a[i]>b[i]) ans += ((long long)(a[i]-b[i])/2);
        return ans;
    }
};