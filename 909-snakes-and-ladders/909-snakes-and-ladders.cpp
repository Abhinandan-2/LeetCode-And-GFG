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

/*

     
    int n = k.size();
    vector<vector<int>> la;
    
        for(int i=0;i<n/2;i++)
        {
            swap(k[i],k[n-i-1]);
        }
        int cal;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(k[i][j]!=-1)
                {
                    // cout<<i<<" "<<j<<" ";
                    cal = i*n;
                    if(i%2==0)
                        cal+=(j+1);
                    else
                        cal+=(n-j);
                    la.push_back({cal,k[i][j]});
                    // cout<<cal<<" "<<k[i][j]<<endl;
                }
            }
        }
        
    vector<vector<int>> a(n*n+1);
    vector<int> v(n*n+1,-1);
    
    unordered_map<int,int> m;
    int laSize= la.size() ;
    for(int i=0;i<laSize;i++)
    {  
       
        a[la[i][0]].push_back(la[i][1]);
        m[la[i][0]] = la[i][1];
    }
    
    
   
   
    int h ,p;
    for(int i=1;i<n*n;i++)
    {
        for(int j=1;j<=6;j++)
        {
            if(m.count(i+j))
            {
                a[i].push_back(m[i+j]);
            }
            else
            {
                if(i+j>n*n)
                break;
                a[i].push_back(i+j);
            }
        }
    }
  
    
    queue<int> q;
    v[1] = 1;
    q.push(1);
    int ans = 0;
    while(!q.empty())
    {
        h = q.size();
        ans++;
        while(h--)
        {
            p = q.front();
            q.pop();
            // cout<<p<<" ";
            for(int i=0;i<a[p].size();i++)
            {
                if(a[p][i]==n*n)
                return ans;
                if(v[a[p][i]]==-1)
                {
                    v[a[p][i]]=1;
                    q.push(a[p][i]);
                }
            }
        }
        // cout<<endl;
    }
    
    return -1;
        

*/