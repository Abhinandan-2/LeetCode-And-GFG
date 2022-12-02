class Solution {
public:
    int maxArea(vector<int>& a) {
        
        
        int n = a.size();
        int i=0, j= n-1 , ans = -1,w,m ;
        while(i<n&&j>=0&&i<j)
        {
            w = (j-i);
            m = min(a[i],a[j]);
            ans = max(ans,w*m);
            if(a[i]<a[j])
                i++;
            else
                j--;
                
        }
        
        return ans;
        
    }
};