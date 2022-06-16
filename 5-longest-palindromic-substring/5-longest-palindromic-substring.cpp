class Solution {
public:
    string longestPalindrome(string a) {
        
        int n = a.size(),ans=0,l,h,f;
        string res;
        for(int i=0;i<n;i++)
        {
            l = i;
            h = i;
            while(l>=0&&h<n&&a[l]==a[h])
            {
                f = h-l+1;
                if(f>ans)
                {
                    ans = f;
                    res = a.substr(l,f);
                }
                l--;
                h++;
            }
            l=i-1;
            h = i;
            while(l>=0&&h<n&&a[l]==a[h])
            {
                f = h-l+1;
                if(f>ans)
                {
                    ans = f;
                    res = a.substr(l,f);
                }
                l--;
                h++;
            }
        }
        
        return res;
        
    }
};