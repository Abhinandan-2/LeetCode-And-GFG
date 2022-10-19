class com{
    public :
    bool operator()(pair<int,string> a,pair<int,string> b){
        if(a.first==b.first) return a.second<b.second;
        return a.first>b.first;
    }  
};
class Solution {
public:    
    vector<string> topKFrequent(vector<string>& a, int k) {
        unordered_map<string,int> m;
        for(auto i:a) m[i]++;
        priority_queue<pair<int,string>,vector<pair<int,string>>,com> q;
        pair<int,string> p;
        for(auto i:m){
            // p =;
            q.push({i.second,i.first});
            if(q.size()>k) q.pop();
        }
        vector<string> ans;
        while(!q.empty()){
            // cout<<q.top().first<<" "<<q.top().second<<endl;
            ans.push_back(q.top().second);q.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};