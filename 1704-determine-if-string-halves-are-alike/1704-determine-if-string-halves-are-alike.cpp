class Solution {
public:
    bool halvesAreAlike(string a) {
        int f=0, s=0, n = a.size(),m = n/2;
        for(int i=0;i<n;i++){
            if(i<m&&(a[i]=='a'||a[i]=='A'||a[i]=='e'||a[i]=='E'||a[i]=='o'||a[i]=='O'||a[i]=='I'||a[i]=='i'||a[i]=='u'||a[i]=='U')) f++;
             else if(i>=m&&(a[i]=='a'||a[i]=='A'||a[i]=='e'||a[i]=='E'||a[i]=='o'||a[i]=='O'||a[i]=='I'||a[i]=='i'||a[i]=='u'||a[i]=='U')) s++;
        }
        return f==s;             
    }
};