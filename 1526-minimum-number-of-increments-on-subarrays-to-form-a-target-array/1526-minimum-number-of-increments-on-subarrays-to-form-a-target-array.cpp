class Solution {
public:
    int minNumberOperations(vector<int>& a) {
        
        int n = a.size(),ans=0;
        
        for(int i=0;i<n;i++)
        {
            if(i==0)
                ans+=a[i];
            else
            {
                if(a[i]>a[i-1])
                    ans += (a[i]-a[i-1]);
            }
        }
        return ans;
        
    }
};