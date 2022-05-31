class Solution {
    
    bool allZero(vector<vector<int>> &a)
    {
        for(auto i:a)
            for(auto j:i)
                if(j!=0)
                    return 0;
        return 1;
    }
    
    void call(vector<vector<int>> &a,int i,int j,int count,int &ans,int x[],int y[])
    {
        // cout<<"-->"<<i<<" "<<j<<" "<<count<<endl;
        // //cout<<"-->";
        // for(auto i:a)
        // {
        //     for(auto j:i)
        //         cout<<j<<" ";
        //     cout<<endl;
        // }
        int n = a.size() ,m= a[0].size(),x1,y1;
        if(allZero(a))
        {
            //cout<<count;
            ans = min(ans,count);
            //count =0;
        }
        if(i>=n||j>=m)
            return ;
        
        int q ,w;
        if(j==m-1)
        {
            q = i+1;
            w = 0; 
        }
        else
        {
            q = i;
            w = j+1;
        }
        call(a,q,w,count,ans,x,y);
        for(int k=0;k<4;k++)
        {
            x1 = i+x[k];
            y1 = j+y[k];
            if(x1>=0&&x1<n&&y1>=0&&y1<m)
            {
                if(a[x1][y1]==1)
                    a[x1][y1] =0;
                else
                    a[x1][y1] = 1;
            }
        }
        if(a[i][j]==1)
            a[i][j]=0;
        else
            a[i][j]=1;
        call(a,q,w,count+1,ans,x,y);
        for(int k=0;k<4;k++)
        {
            x1 = i+x[k];
            y1 = j+y[k];
            if(x1>=0&&x1<n&&y1>=0&&y1<m)
            {
                if(a[x1][y1]==1)
                    a[x1][y1] =0;
                else
                    a[x1][y1] = 1;
            }
        }
        if(a[i][j]==1)
            a[i][j]=0;
        else
            a[i][j]=1;
        return ;
        
    }
    
    
public:
    int minFlips(vector<vector<int>>& a) {
        
        int n = a.size() , m = a[0].size();
        int x[] = {0,0,1,-1};
        int y[] = {1,-1,0,0};
        int ans =INT_MAX, count =0 ;
        
        call(a,0,0,count,ans,x,y);
        if(ans==INT_MAX)
           return -1;
        return ans;
    }
};