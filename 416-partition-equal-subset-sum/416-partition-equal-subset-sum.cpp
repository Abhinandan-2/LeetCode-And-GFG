class Solution {
public:
    bool canPartition(vector<int>& a) {
        
        int n = a.size();
        int sum = accumulate(a.begin(),a.end(),0);
        if(sum%2)
            return 0;
        
        vector<bool> v(sum/2+1,0),h(sum/2+1,0);
        
        v[0] = 1;
        
        for(int i=0;i<n;i++)
        {
            h = v;
            for(int j=1;j<=sum/2;j++)
            {
                if(v[j]==0&&j>=a[i])
                {
                    v[j] = h[j-a[i]];
                }
            }
            if(v[sum/2]==1)
                return 1;
        }
        
        return v[sum/2];
        
        
        
    }
};