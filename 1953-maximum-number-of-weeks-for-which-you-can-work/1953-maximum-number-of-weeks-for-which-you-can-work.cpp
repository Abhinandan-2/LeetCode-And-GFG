class Solution {
public:
    long long numberOfWeeks(vector<int>& a) {
        
        int n = a.size();
        if(n==1)
            return 1;
        
        long long sum=0,h,mx=0;
        
        for(auto i:a)
        {
            sum+=i;
            mx = max(mx,(long long)i);
        }
        h = sum/2;
        if(mx>h)
        {
            h = sum-mx;
            h *=2;
            h++;
            return h;
        }
        return sum;

    }
};