class Solution {
public:
    string reformat(string a) {
        
        int n = a.size();
        string h,k,ans;
        for(int i=0;i<n;i++)
        {
            if(a[i]>=48&&a[i]<=57)
                k.push_back(a[i]);
            else
                h.push_back(a[i]);
        }
        
        n = h.size();
        int m = k.size();
        if(abs(n-m)>1)
            return "";
        if(n<m)
            swap(h,k);
        n = h.size();
        m = k.size();
        int i=0,j=0;
        while(i<n&&j<m)
        {
            ans.push_back(h[i]);
            ans.push_back(k[j]);
            i++;
            j++;   
        }
        //cout<<h<<' '<<k;
        if(i<n)
            ans.push_back(h[i]);
        
        return ans;
        
        
        
    }
};