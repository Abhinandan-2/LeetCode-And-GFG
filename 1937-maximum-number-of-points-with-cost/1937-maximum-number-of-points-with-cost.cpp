class Solution {
public:
    long long maxPoints(vector<vector<int>>& a) {
        
        int n = a.size() , m = a[0].size();
        
        vector<vector<long long>> ans(n,vector<long long> (m,0));
        vector<long long> left(m,0) , right(m,0);
        long long res =0 ;
        
        for(int j=0;j<m;j++)
        {
            ans[0][j] = a[0][j];
            res = max(res,ans[0][j]);
        }
        for(int i=1;i<n;i++)
        {
            left[0] = ans[i-1][0];
            for(int j=1;j<m;j++)
                left[j] = max(ans[i-1][j],left[j-1]-1);
            
            right[m-1] = ans[i-1][m-1];
            for(int j=m-2;j>=0;j--)
                right[j] = max(ans[i-1][j],right[j+1]-1);
            
            for(int j=0;j<m;j++)
            {
                ans[i][j] = a[i][j]+max(left[j],right[j]);
                res = max(res,ans[i][j]);
            }
            
        }
        
        return res;  
        
    }
};

/*

// Let's try it with an example

[1,  3,  4,  2,  5] 
__  __  __  __  __
 0   1   2   3   4

what is max in left side of 0th element nothing, so it should have just above value
 1   __  __  __  __
 0   1   2   3   4

for 1th element, we have two choices, {above - 0, 0th - (1 - 0) }
0th = left[0]
left[1] = max { 3, 1 - 1 } = 3
 1   3  __  __  __
 0   1   2   3   4

for 2nd element, we have three choices, {above - 0, 0th - (2 - 0), 1st - (2 - 1) }
max of  0th - (1 - 0), 1st - (0)  = left[1] 
max of  0th - (1 - 0) - 1, 1st - (0) - 1  = left[1] - 1
left[1] = max { 4, 3 - 1 } = 4
 1   3   4  __  __
 0   1   2   3   4

for 3rd element, we have four choices, {above - 0, 0th - (3 - 0), 1st - (3 - 1), 2nd - (3 - 2) }
0th - (2 - 0), 1st - (2 - 1), 2nd - (0)  = left[2] 
max of  0th - (2 - 0) - 1, 1st - (2 - 1) - 1, 2nd - (0) - 1  = left[2] - 1
left[1] = max { 2, 4 - 1 } = 3
 1   3   4   3  __
 0   1   2   3   4

continue this, and now you will understand why left gives the max of all left elements

*/