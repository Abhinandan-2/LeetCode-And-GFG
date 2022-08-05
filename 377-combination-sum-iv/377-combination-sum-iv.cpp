class Solution {
public:
    int combinationSum4(vector<int>& a, int t) {
        
        vector<unsigned long long> sum(t+1,0);
        sum[0] = 1;
        for(int i=1;i<=t;i++)
        {
            for(int j=0;j<a.size();j++)
            {
                if(a[j]<=i)
                    sum[i] += sum[i-a[j]];
            }
        }
        
        return (int)sum[t];
        
    }
};