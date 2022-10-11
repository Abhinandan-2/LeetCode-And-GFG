class Solution {
public:
    bool increasingTriplet(vector<int>& a) {
        int n = a.size() , x=INT_MAX ,y= INT_MAX;
        for(auto i:a){
            if(i>y) return 1;
            else if(i<=x) x = i;
            else y = i;
        }
        return 0;
    }
};