class Solution {
    
    bool call(vector<vector<int>> &a,int i,int j,int d)
    {
        // cout<<i<<" "<<j<<endl;
        int n = a.size(), m = a[0].size();
        if(i==0&&j==0)
            return 0;
        if(i==n-1&&j==m-1)
        {
            if(d==3&&(a[i][j]==1||a[i][j]==3||a[i][j]==5))
                return 1;
            if(d==2&&(a[i][j]==1||a[i][j]==4||a[i][j]==6))
                return 1;
            if(d==1&&(a[i][j]==2||a[i][j]==5||a[i][j]==6))
                return 1;
            if(d==0&&(a[i][j]==2||a[i][j]==3||a[i][j]==4))
                return 1;
            return 0;
        }
        if(i>=n|j>=m||i<0||j<0)
            return 0;
        
        if(d==0)
        {
            if(!(a[i][j]==2||a[i][j]==3||a[i][j]==4))
                return 0;
            if(a[i][j]==2)
                return call(a,i-1,j,0);
            else if(a[i][j]==3)
                return call(a,i,j-1,2);
            else
                return call(a,i,j+1,3);
        }
        if(d==1)
        {
            if(!(a[i][j]==2||a[i][j]==5||a[i][j]==6))
                return 0;
            if(a[i][j]==2)
                return call(a,i+1,j,1);
            else if(a[i][j]==5)
                return call(a,i,j-1,2);
            else
                return call(a,i,j+1,3);
        }
        if(d==2)
        {
            if(!(a[i][j]==1||a[i][j]==4||a[i][j]==6))
                return 0;
            if(a[i][j]==1)
                return call(a,i,j-1,2);
            else if(a[i][j]==4)
                return call(a,i+1,j,1);
            else
                return call(a,i-1,j,0);
        }
        if(d==3)
        {
            if(!(a[i][j]==1||a[i][j]==3||a[i][j]==5))
                return 0;
            if(a[i][j]==1)
                return call(a,i,j+1,3);
            else if(a[i][j]==3)
                return call(a,i+1,j,1);
            else
                return call(a,i-1,j,0);
        }
        return 0;
    }
    
public:
    bool hasValidPath(vector<vector<int>>& a) {
        
        int n = a.size(), m = a[0].size();
        if(n==1&&m==1)
            return 1;
        
        if(a[0][0]==5)
            return 0;
        
        if(a[0][0]==1||a[0][0]==6)
            return call(a,0,1,3);
        else if(a[0][0]==2||a[0][0]==3)
            return call(a,1,0,1);
        
        return call(a,1,0,1)||call(a,0,1,3);
    }
};

// [[6,1,1,1,1,1,1,1,1,1,1,1,1,3],[4,1,1,1,1,1,1,1,1,1,1,1,1,5],[6,1,1,1,1,1,1,1,1,1,1,1,1,3],[4,1,1,1,1,1,1,1,1,1,1,1,1,5],[6,1,1,1,1,1,1,1,1,1,1,1,1,3],[4,1,1,1,1,1,1,1,1,1,1,1,1,5],[6,1,1,1,1,1,1,1,1,1,1,1,1,3],[4,1,1,1,1,1,1,1,1,1,1,1,1,5],[6,1,1,1,1,1,1,1,1,1,1,1,1,3],[4,1,1,1,1,1,1,1,1,1,1,1,1,5],[6,1,1,1,1,1,1,1,1,1,1,1,1,3],[4,1,1,1,1,1,1,1,1,1,1,1,1,5],[6,1,1,1,1,1,1,1,1,1,1,1,1,3],[4,1,1,1,1,1,1,1,1,1,1,1,1,5],[6,1,1,1,1,1,1,1,1,1,1,1,1,3]]
