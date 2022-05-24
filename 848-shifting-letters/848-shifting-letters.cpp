class Solution {
public:
    string shiftingLetters(string a, vector<int>& b) {
        
        int n=a.size() ;
        b[n-1] = b[n-1]%26;
        for(int i=n-2;i>=0;i--)
        {
            b[i] += b[i+1];
            b[i ]%= 26;
        }
        int h,k;
        for(int i=0;i<n;i++)
        {
            h = a[i]+b[i];
            if(h>122)
            {
                k = h-122;
                k = 96+k;
                a[i] = k;
            }
            else
                a[i] = h;
        }
        return a;
        
    }
};