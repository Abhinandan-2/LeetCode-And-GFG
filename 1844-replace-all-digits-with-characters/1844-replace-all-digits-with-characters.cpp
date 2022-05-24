class Solution {
public:
    string replaceDigits(string a) {
        
        int n = a.size();
        for(int i=1;i<n;i+=2)
        {
            a[i] = a[i-1]+a[i]-48;
        }
        return a;
        
    }
};