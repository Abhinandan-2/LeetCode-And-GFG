class Solution {
public:
    bool findSubarrays(vector<int>& a) {
        
        int n = a.size(),sum;
        unordered_map<int,int> m;
        
        for(int i=0;i<n-1;i++)
        {
            sum = a[i]+a[i+1];
            if(m.count(sum))
                return 1;
            m[sum]++;
        }
        return 0;
        
    }
};