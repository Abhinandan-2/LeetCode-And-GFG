class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& left) {
        
        int n = left.size(), m = left[0].size();
        vector<vector<int>> up = left;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(left[i][j]!=0)
                    left[i][j] = j==0 ? 1 : (left[i][j-1]+1==0 ? 1 : left[i][j-1]+1);
                else
                    left[i][j]=-1;
            }
        for(int j=0;j<m;j++)
            for(int i=0;i<n;i++){
                if(up[i][j]!=0)
                    up[i][j] = i==0 ? 1 : (up[i-1][j]+1==0 ? 1 : up[i-1][j]+1);
                else
                    up[i][j]=-1;
            }
        
        int ans =0 ,maxSide,u,l;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(left[i][j]>0)
                {
                    maxSide = min(i,j);
                    while(maxSide>=0)
                    {
                        u = up[i-maxSide][j];
                        l = left[i][j-maxSide];
                        if(left[i][j]-l!=maxSide||up[i][j]-u!=maxSide)
                        {
                            maxSide--;
                            continue;
                        }
                        l = left[i-maxSide][j-maxSide];
                        u = up[i-maxSide][j-maxSide];
                        if(left[i-maxSide][j]-l!=maxSide||up[i][j-maxSide]-u!=maxSide)
                        {
                            maxSide--;
                            continue;
                        }
                        ans = max(ans,maxSide+1);
                        break;
                    }
                }
            }
        }
        
        return ans*ans;
        
    }
};