class Solution {
public:
    int destroyTargets(vector<int>& a, int t) {
        
        int n = a.size(),mx=0, mn =INT_MAX;
        
        unordered_map<int,int> m,v;
        
        for(auto i:a){
            m[i%t]++;
        }
        
        for(auto i:m){
            if(i.second>mx){
                mx = i.second;
                v.clear();
                v[i.first]++;
            }
            else if(i.second==mx)
                v[i.first]++;
        }
        
        for(int i=0;i<n;i++){
            
            if(v.count(a[i]%t)){
                mn = min(mn,a[i]);
            }
            
        }
        
        return mn;
        
        
    }
};