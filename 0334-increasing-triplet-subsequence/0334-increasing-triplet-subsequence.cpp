class Solution {
public:
    bool increasingTriplet(vector<int>& a) {
        int n = a.size() , x ,y= INT_MAX;
        if(n<3) return 0;
        x = a[0];
        for(int i=1;i<n;i++){
            if(a[i]>y) return 1;
            else if(a[i]<=x) x = a[i];
            else y = a[i];
        }
        return 0;
    }
};