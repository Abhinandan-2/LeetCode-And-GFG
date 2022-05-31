class Solution {
    
    int solve(int x1,int y1,int t,vector<vector<int>> &x)
    {
        vector<int> &a = x[x1] , &b = x[y1];
        
        int i=0,j=0 ,n = a.size() , m = b.size();
        while(i<n&&a[i]<=t)
            i++;
        while(j<m&&b[j]<=t)
            j++;
        while(i<n&&j<m)
        {
            if(a[i]==b[j])
                return a[i];
            if(a[i]<b[j])
                i++;
            else
                j++;
        }
        return -1;
    }
    
public:
    
    static bool com(vector<int> &a,vector<int> &b)
    {
        if(a[1]==b[1])
            return a[0]<b[0];
        return a[1]<b[1];
    }
    
    int minAreaRect(vector<vector<int>>& a) {
        
        int n = a.size() , m  = 4e4+7;
        vector<vector<int>> y(m) , x(m);
        
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++)
            x[a[i][0]].push_back(a[i][1]);
        
        sort(a.begin(),a.end(),com);
        for(int i=0;i<n;i++)
            y[a[i][1]].push_back(a[i][0]); 
        
        // for(int i=0;i<m;i++)
        // {
        //     if(y[i].size()>0)
        //     {
        //         for(auto j:y[i])
        //             cout<<j<<" ";
        //         cout<<endl;
        //     }
        // }
        // for(int i=0;i<m;i++)
        // {
        //     if(x[i].size()>0)
        //     {
        //         for(auto j:x[i])
        //             cout<<j<<" ";
        //         cout<<endl;
        //     }
        // }
        
        int ans = INT_MAX,f,h,w;
        
        for(int i=0;i<m;i++)
        {
            if(y[i].size()>1)
            {
                vector<int> &v = y[i];
                for(int j=0;j<v.size();j++)
                {
                    for(int k=j+1;k<v.size();k++)
                    {
                        f = solve(v[j],v[k],i,x);
                        if(f!=-1)
                        {
                            h = abs(f-i);
                            w = abs(v[k]-v[j]);
                            ans = min(ans,w*h);
                        }
                    }
                }
            }
        }
        if(ans==INT_MAX)
            return 0;
        return ans;
        
        
    }
};