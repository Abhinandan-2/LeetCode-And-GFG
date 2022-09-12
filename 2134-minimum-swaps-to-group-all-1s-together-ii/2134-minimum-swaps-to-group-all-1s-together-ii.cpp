class Solution {
public:
    int minSwaps(vector<int>& a) {
        int n = a.size() , ans = INT_MAX, ones =0 , c=0 ;
        for(auto i:a) if(i==1) ones++;
        for(int i=0;i<ones;i++) if(a[i]==0) c++;
        ans = min(ans,c);
        for(int i=0;i<n-1;i++){
            if(a[i]==0) c--;
            if(a[(i+ones)%n]==0) c++;
            ans = min(ans,c);
        }
        return ans; 
    }
};