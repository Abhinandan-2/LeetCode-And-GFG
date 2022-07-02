class Solution {
public:
    int maxArea(int h, int w, vector<int>& a, vector<int>& b) {
        
        int n = a.size() , m = b.size();
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int mx = -1, mxx = 1;
        
        for(int i=0;i<n;i++)
        {
            if(i!=0)
            mx = max(mx,a[i]-a[i-1]);
            else
            mx = max(mx,a[i]);
        }
        mx = max(mx,h-a[n-1]);
        for(int i=0;i<m;i++)
        {
            if(i!=0)
            mxx = max(mxx,b[i]-b[i-1]);
            else
            mxx = max(mxx,b[i]);
        }
        mxx = max(mxx,w-b[m-1]);
        
        long long ans = (long long)mx*mxx,mod = 1e9+7;
        ans %= mod;
        return (int)ans;
        
        
    }
};