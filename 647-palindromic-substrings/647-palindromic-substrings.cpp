class Solution {
public:
    int countSubstrings(string a) {
        
        int n = a.size();
        int ans = 1 , l  , h ;
        for(int i=1;i<n;i++)
        {
            ans++;
            l = i-1;
            h = i;
            while(l>=0&&h<n)
            {
                if(a[l]==a[h])
                    ans++;
                else
                    break;
                l--;
                h++;
            }
            l = i-1;
            h = i+1;
            while(l>=0&&h<n)
            {
                if(a[l]==a[h])
                    ans++;
                else
                    break;
                l--;
                h++;
            }
        }
        
        return ans;
        
        
    }
};