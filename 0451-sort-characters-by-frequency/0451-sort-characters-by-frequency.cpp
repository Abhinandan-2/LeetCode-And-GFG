class Solution {
public:
    string frequencySort(string a) {
        
        int n= a.size(),h;
        
        unordered_map<char,int> m;
        
        for(auto i:a) m[i]++;
        vector<pair<int,char>> v;
        string ans;
        
        for(auto i:m){
            
            v.push_back({i.second,i.first});
            
        }
        sort(v.begin(),v.end(),greater<pair<int,char>> ()) ;
        n = v.size();
        for(int i=0;i<n;i++){
            
            h = v[i].first;
            while(h--){
                ans.push_back(v[i].second);
            }
            
        }
        return ans;
    }
};