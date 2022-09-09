class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& a) {
        int n = a.size(),pos,ans=0;
        vector<int> mx(n,0),h;
        sort(a.begin(),a.end());
        mx[n-1]= a[n-1][1];
        for(int i=n-2;i>=0;i--) mx[i] = max(mx[i+1],a[i][1]);
        for(int i=n-2;i>=0;i--){
            h = {a[i][0],INT_MAX};
            pos = upper_bound(a.begin(),a.end(),h)-a.begin();
            if(pos==n) continue;
            if(mx[pos]>a[i][1]) ans++;
        }
        return ans;
    }
};