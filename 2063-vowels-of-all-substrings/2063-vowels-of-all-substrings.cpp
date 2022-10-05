class Solution {
public:
    long long countVowels(string a) {
        
        int n = a.size(),c=0;
        vector<int> v(n,0);
        long long ans =0 , mul =0 , sum =0 ;
        for(int i=n-1;i>=0;i--){
            c++;
            if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'){
                v[i] = c;
                c=0;
            }
        }
        c=1;
        for(int i=0;i<n;i++){
            if(v[i]!=0){
                sum += v[i];
                mul += c*(v[i]);
                c++;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            ans += mul;
            if(v[i]!=0){
                mul -= sum;
                sum -= v[i];
            }
        }
        return ans;
        
    }
};