class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& vec) {
        
        
        int n = vec.size(),cal;
        unordered_map<int,int> m;
        for(int i=0;i<n/2;i++)
            swap(vec[i],vec[n-i-1]);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vec[i][j]!=-1){
                cal = i*n;
                if(i%2==0)
                    cal += (j+1);
                else
                    cal += (n-j);
                m[cal] = vec[i][j];
                }
            }
        }
        // for(auto i:m)
        //     cout<<i.first<<" "<<i.second<<endl;
        int last = n*n;
        vector<vector<int>> a(last+1);
        vector<int> v(last+1,-1);
        for(int i=1;i<last;i++)
        {
            for(int j=1;j<=6;j++)
            {
                if(m.count(i+j))
                    a[i].push_back(m[i+j]);
                else
                {
                    if(i+j>last)
                        break;
                    a[i].push_back(i+j);
                }
            }
        }
        
        queue<int> q;
        q.push(1);
        v[1] = 1;
        int ans =0, h, p;
        
        while(!q.empty())
        {
            h = q.size();
            ans++;
            while(h--)
            {
                p = q.front();
                q.pop();
                for(int i=0;i<a[p].size();i++)
                {
                    if(v[a[p][i]]==-1)
                    {
                        if(a[p][i]==last)
                            return ans;
                        q.push(a[p][i]);
                        v[a[p][i]]=1;
                    }
                }
            }
        }
        
        return -1;
      
    }
};
