class Solution {
public:
    int numberOfSubarrays(vector<int>& a, int k) {
        int n=a.size(),ans =0 , i=0 , j= -1 ,f=0,s=0;
        while(i<n){
            if(a[i]%2!=0) s++;
            if(s==k) break;
            i++;
        }
        if(s!=k) return 0;
        while(i<n){
            s=1;f=1;
            j++;
            while(a[j]%2==0){j++;f++;}
            i++;
            while(i<n&&a[i]%2==0){i++;s++;}
            ans += f*s;
        }
        return ans;  
    }
};