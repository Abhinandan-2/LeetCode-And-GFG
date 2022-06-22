class Solution {
public:
    int maxProfit(vector<int>& a) {
        
        int n = a.size() , ans =0 , f =0 ;
        f = a[0];
        for(int i=1;i<n;i++)
        {
            if(a[i]<f)
            {
                f = a[i];
            }
            else
            {
                ans = max(ans,a[i]-f);
            }
        }
        return ans;
        
        
    }
};