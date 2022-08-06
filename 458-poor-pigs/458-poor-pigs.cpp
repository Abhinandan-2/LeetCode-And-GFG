class Solution {
public:
    int poorPigs(int t, int h, int k) {
        
        if(t==1)
            return 0;
        int b = k/h+1;
        t--;
        int g = log2(t)/log2(b);
        g++;
        return g;
        
    }
};