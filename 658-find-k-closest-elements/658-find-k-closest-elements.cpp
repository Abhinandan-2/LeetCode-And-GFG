class Solution {
public:
    vector<int> findClosestElements(vector<int>& a, int k, int x) {
        
        int n = a.size(),m;
        vector<int> b,c;
        
        int j = lower_bound(a.begin(),a.end(),x)-a.begin();
        int i = j-1;
        while(k--)
        {
            if(i<0)
            {
                c.push_back(a[j]);
                j++;
            }
            else if(j==n)
            {
                b.push_back(a[i]);
                i--;
            }
            else
            {
                if(abs(a[i]-x)<=abs(a[j]-x))
                {
                    b.push_back(a[i]);
                    i--;
                }
                else
                {
                    c.push_back(a[j]);
                    j++;
                }
            }
        }
        
        
        vector<int> ans ;
        
        i=0;
        j=0;
        n = b.size();
        m = c.size();
        reverse(b.begin(),b.end());
        
        while(i<n&&j<m)
        {
            if(b[i]<=c[j])
            {
                ans.push_back(b[i]);
                i++;
            }
            else
            {
                ans.push_back(c[j]);
                j++;
            }
        }
        
        while(i<n)
        {
            
                ans.push_back(b[i]);
                i++;
        }
        
        
        while(j<m)
        {
            
                ans.push_back(c[j]);
                j++;
        }
        return ans;
        
        
        
        
        
        
    }
};