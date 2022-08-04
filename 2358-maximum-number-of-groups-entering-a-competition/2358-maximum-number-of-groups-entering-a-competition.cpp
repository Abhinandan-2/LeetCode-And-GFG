class Solution {
public:
    int maximumGroups(vector<int>& a) {
        
        int n = a.size() , ans = 0,sum=0,c=0,preSum=0,preC=0;
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++)
        {
            sum += a[i];
            c++;
            if(sum>preSum&&c>preC)
            {
                ans++;
                preSum =sum;
                preC = c;
                sum =0;
                c=0;
            }
        }
        return ans;
        
    }
};