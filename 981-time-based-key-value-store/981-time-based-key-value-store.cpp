class TimeMap {
    unordered_map<string,vector<pair<int,string>>> m;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp,value});
        return;
    }
    
    string get(string key, int timestamp) {
        vector<pair<int,string>> &v = m[key];
        pair<int,string> p =  {timestamp,""};
        int in = lower_bound(v.begin(),v.end(),p)-v.begin();
        if(in>=v.size()||v[in].first!=timestamp) in--;
        if(in<0) return "";
        return v[in].second;
    }
};