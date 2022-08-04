class Solution {
public:
    int distanceBetweenBusStops(vector<int>& a, int s, int d) {
        
        int n = a.size(),res1=0,res2=0;
        int sum = accumulate(a.begin(),a.end(),0);
        if(s>d)
            swap(s,d);
        for(int i=s;i<d;i++)
            res1 += a[i];
        res2 = sum-res1;
        return min(res1,res2);
        
    }
};