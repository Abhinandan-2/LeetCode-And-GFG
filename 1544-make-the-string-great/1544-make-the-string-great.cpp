class Solution {
public:
    string makeGood(string a) {
        
        stack<char> s;
        int n = a.size();
        for(int i=0;i<n;i++){
            if(s.empty()||abs((int)s.top()-(int)a[i])!=32) s.push(a[i]);
            else s.pop();
            
        }
        string ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};