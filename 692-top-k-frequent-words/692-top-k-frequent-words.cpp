class Solution {
public:
    
    static bool com(pair<int,string> &a,pair<int,string> &b)
    {
        if(a.first==b.first)
            return a.second<b.second;
        return a.first>b.first;
    }
    
    vector<string> topKFrequent(vector<string>& a, int k) {
        
       unordered_map<string,int> m;
        
        for(auto i:a)
        {
            m[i]++;
        }
        
        // priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> q;
        // pair<int,string> p;
        // for(auto i:m)
        // {
        //     p ={i.second,i.first} ;
        //     q.push(p);
        //     if(q.size()>k)
        //         q.pop();
        // }
            
        vector<pair<int,string>> ans;
        vector<string> res;
        for(auto i:m)
        {
            ans.push_back({i.second,i.first});
        }
        int i=0;
        sort(ans.begin(),ans.end(),com);
        while(k--)
            res.push_back(ans[i++].second);
        
        return res;
        
    }
};