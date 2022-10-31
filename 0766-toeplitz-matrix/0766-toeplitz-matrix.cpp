class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& a) {
        
        int n = a.size() , m = a[0].size();
        
        int x=n-1,y=0,i=0, j = 0,t;
        
        while(x>=0){
            i = x;
            j = y;
            while(i<n-1&&j<m-1){
                if(a[i][j]!=a[i+1][j+1]) return 0;
                i++;
                j++;
            }
            x--;
        }
        x=0;
        y= 1;
        while(y<m){
            i = x;
            j = y;
            while(i<n-1&&j<m-1){
                if(a[i][j]!=a[i+1][j+1]) return 0;
                i++;
                j++;
            }
            y++;
        }
        return 1;
        
    }
};