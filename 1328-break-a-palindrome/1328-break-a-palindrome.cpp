class Solution {
public:
    string breakPalindrome(string a) {
        int n = a.size();
        if(n==1) return "";
        for(int i=0;i<n;i++) if((n%2==0||i!=n/2)&&(a[i]!='a')) {a[i] = 'a';return a;}
        a[n-1] = 'b';
        return a;   
    }
};