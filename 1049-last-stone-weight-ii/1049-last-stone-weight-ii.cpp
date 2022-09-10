class Solution {
public:
    int lastStoneWeightII(vector<int>& a) {
        int n = a.size(),sum = accumulate(a.begin(),a.end(),0);
        if(n==1) return a[0];
        int tar = sum/2,ans=0;
        vector<int> v(tar+1,0) , h(tar+1,0);
        h[0] = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<=tar;j++){
                if(h[j]==1) {v[j] = 1;continue;}
                j<a[i] ? v[j] = 0 : h[j-a[i]]==1 ? v[j]= 1 :v[j] = 0;
                if(v[j]==1) ans = max(ans,j);
            }
            if(ans==tar) break;
            h =v;
        }
        return abs(ans-(sum-ans));
    }
};