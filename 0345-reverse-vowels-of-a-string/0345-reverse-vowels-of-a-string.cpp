class Solution {
public:
    bool isVowel(char a){
        if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u'||a=='A'||a=='E'||a=='I'||a=='O'||a=='U') return 1;
        return 0;
    }
    string reverseVowels(string a) {
        int n = a.size() ;
        int i =0 , j = n-1;
        while(i<j){
            while(i<n&&!isVowel(a[i])) i++;
            while(j>=0&&!isVowel(a[j])) j--;
            if(i>=j) break;
            swap(a[i],a[j]);
            i++;
            j--;
        }
        return a;
        
    }
};