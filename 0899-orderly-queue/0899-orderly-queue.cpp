class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k > 1){
            sort(s.begin(), s.end());
            return s;
        }
        
        string res = s;
        
        for(int i = 1; i < s.size(); i++){
            res = min(res,s = s.substr(1) + s.substr(0,1));
        }
        
        return res;
    }
};