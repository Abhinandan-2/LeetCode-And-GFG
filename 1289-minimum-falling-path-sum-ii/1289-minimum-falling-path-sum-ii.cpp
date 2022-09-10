class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& a) {
        
        int n = a.size() ;
        if(n==1) return a[0][0];
        
        int fm = INT_MAX, pos ,sm=INT_MAX, mn,in,mn2,num;
        
        for(int i=0;i<n;i++)
        {
            if(a[0][i]<=fm)
            {
                pos = i;
                sm = fm;
                fm = a[0][i];
            }
            else if(a[0][i]<sm)
                sm = a[0][i];     
        }
        for(int i=1;i<n;i++)
        {
            mn = INT_MAX;
            mn2 = INT_MAX;
            for(int j=0;j<n;j++)
            {
                num = a[i][j];
                if(pos==j)
                {
                    num += sm;
                }
                else
                {
                    num += fm;
                }
                if(num<=mn)
                {
                    in = j;
                    mn2 = mn;
                    mn = num;
                }
                else if(num<mn2)
                    mn2 = num;
            }
            pos = in;
            fm = mn;
            sm = mn2;
        }
        return fm;
        
    }
};