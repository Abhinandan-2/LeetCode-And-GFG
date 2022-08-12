
class Solution {
public:
    bool stoneGameIX(vector<int>& b) {
        
        vector<int> a(3, 0);
        
        for (auto i:b)
            a[i%3]++;
        
        bool f = a[0]%2==0 ? 0:1;
        
        if (a[1]==0)
            return a[2]<3 ? 0:f;
        
        if (a[2]==0)
            return a[1]<3 ? 0:f;
        
        if (abs(a[1] - a[2]) > 2)
            return 1;
        
        if(f)
            return 0;
        return 1;
    }
};