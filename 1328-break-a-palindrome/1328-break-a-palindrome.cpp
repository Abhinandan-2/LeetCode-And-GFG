class Solution {
public:
    string breakPalindrome(string a) {
        
        int n = a.size(),f=0;
        if(n==1) return "";
        for(int i=0;i<n;i++){
            if((n%2==0||i!=n/2)&&(a[i]!='a')){
                a[i] = 'a';
                f=1;
                break;
            }
        }
        if(f!=0) return a;
        a[n-1] = 'b';
        return a;
        
    }
};