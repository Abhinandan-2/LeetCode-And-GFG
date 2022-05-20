class Solution {
public:
    string licenseKeyFormatting(string a, int k) {
        
        int n = a.size(),h=0;
        string res;
        for(int i=n-1;i>=0;i--)
        {
            if(h==k)
            {
                res.push_back('-');
                h=0;
            }
            if(a[i]!='-')
            {
                if(a[i]>=97&&a[i]<=122)
                    res.push_back(a[i]-32);
                else
                    res.push_back(a[i]);
                h++;
            }
        }
        while(res.back()=='-')
            res.pop_back();
        reverse(res.begin(),res.end());
        return res;
        
    }
};