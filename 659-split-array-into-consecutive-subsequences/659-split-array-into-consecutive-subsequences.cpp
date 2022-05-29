class Solution {
    
    
    bool allVisited(vector<int> &a)
    {
        for(auto i:a)
            if(i==-1)
                return 0;
        return 1;
    }
    
    vector<pair<int,int>> makePair(vector<int> &a)
    {
        int n = a.size();
        vector<int> v(n,-1);
        vector<pair<int,int>> ans;
        int vis,s,e;
        while(!allVisited(v))
        {
            s = -1;
            e =-1;
            vis = -1;
            for(int i=0;i<n;i++)
            {
                if(v[i]==-1&&a[i]!=vis)
                {
                    if(s==-1)
                    {
                        s = a[i];
                        e = a[i];
                    }
                    else
                    {
                        if(e+1!=a[i])
                        {
                            ans.push_back({s,e});
                            s =a[i];
                            e = a[i];
                        }
                        else
                            e++;
                    }
                    v[i] = 1;
                    vis = a[i];
                }
            }
            ans.push_back({s,e});
        }
        return ans;
    }
    
public:
    bool isPossible(vector<int>& a) {
        
        vector<pair<int,int>> help = makePair(a),main,sm;
        pair<int,int> p ,p1,p2;
        int ans , len;
        // for(auto i:help)
        //     cout<<i.first<<" "<<i.second<<endl;
        for(int i=0;i<help.size();i++)
        {
            if(help[i].second-help[i].first+1>=3)
                main.push_back(help[i]);
            else
                sm.push_back(help[i]);
        }
        
        for(int i=0;i<sm.size();i++)
        {
            p = sm[i];
            ans = -1;
            len = INT_MAX;
            for(int j=0;j<main.size();j++)
            {
                if(p.second-2>=main[j].first&&main[j].second-p.first+1>=3)
                {
                    if(main[j].second<len)
                    {
                        ans = j;
                        len = main[j].second;
                    }
                }
            }
            if(ans==-1)
                return 0;
            p1 = {p.first,main[ans].second};
            p2 = {main[ans].first,p.second};
            main.erase(main.begin()+ans);
            main.push_back(p1);
            main.push_back(p2);
            
        }
        return 1;  
    }
};