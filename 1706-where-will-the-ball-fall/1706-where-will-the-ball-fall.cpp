class Solution {
public:
    vector<int> findBall(vector<vector<int>>& a) {
        
        int n = a.size() , m = a[0].size(),i,j,f;
        vector<int> ans(m);
        
        for(int k=0;k<m;k++)
        {
            i =0 ;
            j= k;
            f =0;
            while(i<n)
            {
                // cout<<i<<" "<<j<<" ";
                if(a[i][j]==1)
                {
                    if(j<m-1&&a[i][j+1]==1)
                    {
                        i++;
                        j++;
                    }
                    else
                    {
                        f=1;
                        break;
                    }
                }
                else
                {
                    if(j>0&&a[i][j-1]==-1)
                    {
                        i++;
                        j--;
                    }
                    else
                    {
                        f=1;
                        break;
                    }
                }
                // cout<<i<<" "<<j<<" ";
            }
            // cout<<endl;
            if(f==1)
                ans[k] = -1;
            else
                ans[k] = j;
            // cout<<ans[i]
        }
        
        return ans;
        
        
    }
};