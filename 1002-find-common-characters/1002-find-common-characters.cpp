class Solution {
public:
    vector<string> commonChars(vector<string>& a) {
        
        vector<string> res;
        unordered_map<char,int> m,ans;
        
        int n = a.size();
        string h;
        for(auto &i:a[0]) ans[i]++;
        
        for(int i=1;i<n;i++){
            m = ans;
            ans.clear();
            for(auto &j:a[i]){
                if(m[j]>0){
                    ans[j]++;
                    m[j]--;
                }
            }
        }
        for(auto &i:ans){
            n = i.second;
            h = i.first;
            while(n--) res.push_back(h);
        }
        return res;
    }
};