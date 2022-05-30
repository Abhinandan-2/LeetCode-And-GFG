class Solution {
public:
    
    static bool com(vector<int> &a,vector<int> &b)
    {
        if(a[1]==b[1])
            return a[0]<b[0];
        return a[1]<b[1];
    }
    
    int intersectionSizeTwo(vector<vector<int>>& a) {
        
        int n = a.size(),h,m,f;
        vector<int> ans;
        sort(a.begin(),a.end(),com);
        
        for(int i=0;i<n;i++)
        {
            h = a[i][1];
            m = upper_bound(ans.begin(),ans.end(),h)-ans.begin();
            if(m==0)
            {
                ans.push_back(a[i][1]-1);
                ans.push_back(a[i][1]);
            }
            else
            {
                m--;
                f=0;
                while(f!=2&&ans[m]>=a[i][0]&&ans[m]<=a[i][1])
                {
                    f++;
                    m--;
                }
                if(f==0)
                {
                    ans.push_back(a[i][1]-1);
                    ans.push_back(a[i][1]);
                }
                else if(f==1)
                {
                    if(binary_search(ans.begin(),ans.end(),a[i][1]))
                    {
                        ans.pop_back();
                        ans.push_back(a[i][1]-1);
                        ans.push_back(a[i][1]);
                    }
                    else
                        ans.push_back(a[i][1]);
                }
            }
        }
        int res = ans.size();
        return res;
        
        
    }
};