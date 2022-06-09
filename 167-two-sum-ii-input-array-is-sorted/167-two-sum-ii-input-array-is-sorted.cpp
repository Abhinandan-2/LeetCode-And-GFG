class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t) {
        
        int n = a.size();
        int i =0, j=n-1;
        while(a[i]+a[j]!=t)
        {
            if(a[i]+a[j]>t)
                j--;
            else
                i++;
        } 
        return {i+1,j+1};
    }
};