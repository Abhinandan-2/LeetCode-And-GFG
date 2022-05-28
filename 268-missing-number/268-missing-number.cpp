class Solution {
public:
    int missingNumber(vector<int>& a) {
        
        int n = a.size();
        
        int i= 0,ans=-1,h;
        while(i<n)
        {
            
            h = a[i];
            while(h!=n&&h!=i)
            {
                swap(a[i],a[h]);
                h = a[i];
            }
            if(h==n)
                ans = i;
            i++;
        }
        if(ans==-1)
            return n;
        return ans;
        
    }
};