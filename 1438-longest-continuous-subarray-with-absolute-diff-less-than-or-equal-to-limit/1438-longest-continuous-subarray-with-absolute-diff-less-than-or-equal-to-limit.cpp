class Solution {
public:
    int longestSubarray(vector<int>& a, int t) {
        
        int n = a.size(),ans =0,mn = INT_MAX,mx = INT_MIN,i=0,j=0 ;
        multiset<int> s;
        
        while(i<n)
        {
            mn = min(mn,a[i]);
            mx = max(mx,a[i]);
            s.insert(a[i]);
            while(mx-mn>t)
            {
                s.erase(s.find(a[j]));
                mn = *s.begin();
                mx = *s.rbegin();
                j++;
            }
            ans = max(ans,i-j+1);
            i++;
        }
        
        return ans;
        
        
    }
};