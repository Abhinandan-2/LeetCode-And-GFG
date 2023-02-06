class Solution {
public:
    bool checkMove(vector<vector<char>>& a, int x, int y, char c) {
        
        int i = x, j =y ;
        char opp = c=='B' ? 'W' : 'B';
        i--;
        while(i>=0&&a[i][j]==opp) i--;
        if(i>=0&&a[i][j]==c&&x-i!=1) return 1;
        i=x+1;
        while(i<8&&a[i][j]==opp) i++;
        if(i<8&&a[i][j]==c&&i-x!=1) return 1;
        i=x;
        j--;
        while(j>=0&&a[i][j]==opp) j--;
        if(j>=0&&a[i][j]==c&&y-j!=1) return 1;
        j=y+1;
        while(j<8&&a[i][j]==opp) j++;
        if(j<8&&a[i][j]==c&&j-y!=1) return 1;
        j=y+1;
        i++;
        while(i<8&&j<8&&a[i][j]==opp){
            i++;
            j++;
        }
        if(i<8&&j<8&&a[i][j]==c&&abs(i-x)!=1) return 1;
        i = x-1;
        j = y-1;
        while(i>=0&&j>=0&&a[i][j]==opp){
            i--;
            j--;
        }
        if(i>=0&&j>=0&&a[i][j]==c&&abs(i-x)!=1) return 1;
        i = x-1;
        j = y+1;
        while(i>=0&&j<8&&a[i][j]==opp){
            i--;
            j++;
        }
        if(i>=0&&j<8&&a[i][j]==c&&abs(i-x)!=1) return 1;
        i=x+1;
        j = y-1;
        while(i<8&&j>=0&&a[i][j]==opp){
            i++;
            j--;
        }
        if(i<8&&j>=0&&a[i][j]==c&&abs(i-x)!=1) return 1;
        return 0;
        
    }
};