class Solution {
public:
    int numSubarraysWithSum(vector<int>& a, int goal) {
        
        unordered_map<int,int> m;
        int n = a.size() , ans =0 , sum =0;
        m[0]++;
        
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
            if(m.count(sum-goal))
                ans += m[sum-goal];
            m[sum]++;
        }
        return ans;
        
    }
};