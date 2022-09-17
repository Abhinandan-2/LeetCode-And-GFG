class Solution {
public:
    int maxVowels(string a, int k) {
        int n = a.size() , c=0 ,ans =0 ;
        for(int i=0;i<k;i++) if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u') c++;
        ans= c;
        for(int i=k;i<n;i++){
            if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u') c++;
            i-=k;
            if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u') c--;
            i+=k;
            ans = max(ans,c);
        }
        return ans;
    }
};