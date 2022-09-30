class Solution {
    vector<int> sequence(vector<int> &a){
        int n = a.size();
        vector<int> ans(n);
        for(int i=n-1;i>=1;i--) a[i]>=a[i-1] ? ( i== n-1 ? ans[i]= 1 : ans[i] = ans[i+1]+1) : ans[i] = 0;
        return ans;
    }
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> inc = sequence(nums),ans;
        reverse(nums.begin(),nums.end());
        vector<int> dec = sequence(nums);
        reverse(dec.begin(),dec.end());
        for(int i=k;i<n-k;i++) if(k==1||inc[i+2]>=k-1&&dec[i-2]>=k-1) ans.push_back(i);
        return ans;
    }
};