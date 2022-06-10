class Solution {
public:
    int minSwaps(vector<vector<int>>& a) {
        
        int n = a.size(),f;
        vector<int> v(n);
        for(int i=0;i<n;i++)
        {
            f =0;
            for(int j=n-1;j>=0;j--)
            {
                if(a[i][j]!=0)
                    break;
                f++;
            }
            v[i] = f;
        }
        int ans =0,t;
        
        for(int i=0;i<n;i++)
        {
            t = n-i-1;
            f =-1;
            for(int j=i;j<n;j++)
            {
                if(v[j]>=t)
                {
                    f = j;
                    break;
                }
            }
            if(f==-1)
                return -1;
            while(f>i)
            {
                swap(v[f],v[f-1]);
                ans++;
                f--;
            }
        }
        
        return ans;
    }
};