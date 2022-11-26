class Solution {
public:
    int jobScheduling(vector<int>& a, vector<int>& b, vector<int>& p) {
        
        map<int,int> m;
        
        int n = a.size();
        
        vector<vector<int>> v;
        
        for(int i=0;i<n;i++){
            v.push_back({a[i],b[i],p[i]});
        }
        
        sort(v.begin(),v.end());
        
        for(int i=n-1;i>=0;i--){
            
            auto it = m.lower_bound(v[i][1]);
            auto ij = m.lower_bound(v[i][0]);
            if(it!=m.end()){
                m[v[i][0]] = max(it->second+v[i][2],ij->second);
            }
            else{
                if(ij!=m.end()){
                    m[v[i][0]] = max(ij->second,v[i][2]);
                }
                else{
                    m[v[i][0]] = v[i][2];
                }
            }
            // cout<<m[v[i][0]]<<" ";
            
        }
        
        // for(auto i:m){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        
        return m[v[0][0]];
        
    }
};