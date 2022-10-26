class Solution {
public:
    bool checkSubarraySum(vector<int>& a, int k) {
        int n = a.size(),pre =0,sum=0;
        for(int i=0;i<n;i++) a[i] = a[i]%k;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            sum += a[i];
            sum %= k;
            if(m.count(sum)) return 1;
            m[pre]++;
            pre = sum;
        }
        return 0;
    }
};