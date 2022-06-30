class Solution {
public:
    int minMoves2(vector<int>& a) {
        
        sort(a.begin(),a.end());
        
        int n = a.size();
        int m = (n+1)/2-1;
        int h = a[m];
        int ans = 0;
        
        for(int i=0;i<n;i++)
            ans += abs(a[i]-h);
        
        return ans;
            

    }
};