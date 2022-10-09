class Solution {
public:
    char minimumChar(unordered_map<char,int> &m){
        char ans = (char)125;
        for(auto i:m) ans  = min(ans,i.first);
        return ans;
    }
    string robotWithString(string a) {
        int n = a.size();
        unordered_map<char,int> m;
        stack<char> s;
        string ans;
        for(auto i:a) m[i]++;
        for(int i=0;i<n;i++){
            m[a[i]]--;
            if(m[a[i]]==0) m.erase(a[i]);
            s.push(a[i]);
            while(!s.empty()&&s.top()<=minimumChar(m)){
                ans += s.top();
                s.pop();
            }
        }
        return ans;
    }
};