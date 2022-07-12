class Solution {
public:
    int search(vector<int>& a, int t) {
        
        int n = a.size();
        int l =0 , h =n-1 , m ;
        
        while(l<=h)
        {
            m= l +(h-l)/2;
            if(a[m]==t)
                return m;
            if(a[m]>=a[l])
            {
                if(t>a[m]||t<a[l])
                    l = m+1;
                else
                    h = m-1;
            }
            else
            {
                if(t>=a[l]||t<a[m])
                    h = m-1;
                else
                    l = m+1;
            }
        }
        
        
        return -1;
        
        
        
    }
};