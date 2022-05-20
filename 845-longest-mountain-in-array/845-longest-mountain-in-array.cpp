class Solution {
public:
    int longestMountain(vector<int>& a) {
        
        int n = a.size();
        
        int i=1 , f =0,ans=0;
        while(i<n)
        {
            if(a[i]>a[i-1])
            {
                f = i-1;
                while(i<n&&a[i]>a[i-1])
                    i++;
                if(i==n)
                    return ans;
                if(a[i]==a[i-1])
                    goto la;
                while(i<n&&a[i]<a[i-1])
                    i++;
                ans = max(i-1-f+1,ans);
                if(i==n)
                    return ans;
            }
            else
                i++;
            la:
            f=0;
        }
        return ans;
        
        
    }
};