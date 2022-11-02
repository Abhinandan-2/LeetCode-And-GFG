class Solution {
public:
    int minMutation(string a, string b, vector<string>& w) {
        
        if(a==b)
            return 0;
        unordered_map<string,int> m,v;
        int n= w.size();
        for(int i=0;i<n;i++)
        {
            m[w[i]]++;
            //cout<<w[i]<<" "<<m[w[i]]<<endl;
        }
        
        if(m[b]==0)
            return -1;
        char x[] = {'A','C','G','T'},c;
        v[a] = 1;
        queue<string> q;
        q.push(a);
        int ans =0,h ;
        string p;
        while(!q.empty())
        {
            h = q.size();
            ans++;
            while(h--)
            {
                p = q.front();
                q.pop();
                //cout<<p<<" ";
                for(int i=0;i<p.size();i++)
                {
                    c = p[i];
                    for(int j=0;j<4;j++)
                    {
                        p[i] = x[j];
                        // cout<<p<<" ";
                        if(p==b)
                            return ans;
                        if(m[p]!=0&&v[p]==0)
                        {
                            // cout<<1<<" ";
                            q.push(p);
                            v[p]++;
                        }
                    }
                    p[i] = c;
                }
                
            }
            // cout<<endl;
        }
        
        
        return -1;
        
        
        
        
        
    }
};