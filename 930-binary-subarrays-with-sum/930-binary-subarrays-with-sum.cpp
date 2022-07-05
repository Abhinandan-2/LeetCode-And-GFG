class Solution {
public:
    int numSubarraysWithSum(vector<int>& a, int goal) {
        
        int n = a.size() , sum =0 , ans =0 , i =0 ,j =0 ,count=0,k;
        if(goal==0)
        {
            for(int i=0;i<n;i++)
            {
                if(a[i]==0)
                {
                    count++;
                    ans +=count;
                }
                else
                    count=0;
            }
            return ans;
        }
        
        
        while(i<n)
        {
            sum+=a[i];
            if(sum==goal)
                break;
            i++;
        }
        
        if(sum!=goal)
            return 0;
        k = j;
        while(k<n&&a[k]==0)
            k++;
        ans += (k-j+1);
        // cout<<ans<<" ";
        i++;
        while(i<n)
        {
            if(a[i]==0)
                ans+=(k-j+1);
            else
            {
                count=0;
                j= k+1;
                k = j;
                while(k<n&&a[k]==0)
                    k++;
                ans += (k-j+1);
            }
            i++;
        }
    return ans;
    }
};