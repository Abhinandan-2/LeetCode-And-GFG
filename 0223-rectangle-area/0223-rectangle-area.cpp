class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        
        int l = ax2-ax1;
        int b = ay2-ay1;
        int ans = l*b;
        l = bx2-bx1;
        b = by2-by1;
        ans += (l*b);
        l =0 ;
        b= 0;
        
        if(bx1>=ax1&&bx1<=ax2) l = min(bx2,ax2)-bx1;
        else if(bx2>=ax1&&bx2<=ax2) l = bx2-max(ax1,bx1);
        else if(bx1<=ax1&&bx2>=ax2) l  = ax2-ax1;
        if(by1>=ay1&&by1<=ay2) b = min(by2,ay2)-by1;
        else if(by2>=ay1&&by2<=ay2) b = by2-max(ay1,by1);
        else if(by1<=ay1&&by2>=ay2) b  = ay2-ay1;
        
        ans -= (l*b);
        return ans;
    }
};