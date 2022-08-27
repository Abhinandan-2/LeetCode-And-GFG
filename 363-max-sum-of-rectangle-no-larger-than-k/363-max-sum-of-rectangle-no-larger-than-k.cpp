class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& a, int target) {
        
        int n = a.size() , m = a[0].size();
        
        for(int i=1;i<n;i++)
            a[i][0] += a[i-1][0];
        
        for(int j=1;j<m;j++)
            a[0][j] += a[0][j-1];
        
        for(int i=1;i<n;i++)
            for(int j=1;j<m;j++)
                a[i][j] += a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        for(int i=0;i<n;i++)
            a[i].insert(a[i].begin(),0);
        m++;
        // for(auto i:a)
        // {
        //     for(auto j:i)
        //         cout<<j<<" ";
        //     cout<<endl;
        // }
        int ans = INT_MIN,sum,tar,dif;
        set<int> s;
        
        for(int j=1;j<m;j++)
        {
            for(int k=j-1;k>=0;k--)
            {
                s.insert(0);
                sum =0 ;
                for(int i=0;i<n;i++)
                {
                    sum = a[i][j]-a[i][k];
                    tar = sum-target;
                    // cout<<tar<<" ";
                    auto it = s.lower_bound(tar);
                    
                    if(it!=s.end())
                    {
                        // cout<<"yes";
                        if(*it==tar)
                            return target;
                        
                            
                        dif= sum-(*it);
                        ans = max(ans,dif);
                        
                    }
                    s.insert(sum);
                    // cout<<sum<<" "<<ans<<endl;
                }
                s.clear();
            }
        }
        
        return ans;
        
    }
};