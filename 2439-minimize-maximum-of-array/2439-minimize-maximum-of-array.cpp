class Solution {
public:
    bool isAns(vector<int> &a,int m){
        if(a[0]>m) return 0;
        int n = a.size();
        long long carry = m-a[0];
        for(int i=1;i<n;i++){
            if(a[i]>m){
                if(carry<(a[i]-m)) return 0;
                carry -= (a[i]-m);
            }
            else carry += (m-a[i]);
        }
        return 1;
    }
    int minimizeArrayValue(vector<int>& a) {
        int n= a.size(), l = a[0] , h = *max_element(a.begin(),a.end()) ,m ,ans;
        while(l<=h){
            m = l+(h-l)/2;
            if(isAns(a,m)){
                ans = m;
                h = m-1;
            }
            else l = m+1; 
        }
        return ans;
    }
};