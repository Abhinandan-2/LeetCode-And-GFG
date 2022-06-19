class Solution {
public:
    double rd,xc,yc;
    
    Solution(double radius, double x_center, double y_center) {
        
        rd = radius;
        xc = x_center;
        yc = y_center;
        
    }
    
    vector<double> randPoint() {
        
        double len = sqrt((double)rand()/INT_MAX);
        len *= rd;
        double ang = (double)rand()/INT_MAX;
        ang *= (2*M_PI);
        double x = cos(ang)*len;
        double y = sin(ang)*len;
        return {x+xc,y+yc};
        
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */