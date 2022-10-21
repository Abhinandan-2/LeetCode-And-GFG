class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        map <int,int> mp;
        for(int i=0;i<n;i++)
        {
            if(mp[nums[i]]==0)
            {
                mp[nums[i]]++;
                if(i>=k)
                    mp.erase(nums[i-k]);
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};