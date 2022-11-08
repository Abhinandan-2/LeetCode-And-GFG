class Solution {
public:
    vector<string> findOcurrences(string a, string first, string second) {
        vector<string> help,ans;
        stringstream c(a);
        string h;
        while(getline(c,h,' ')) help.push_back(h);
        for(int i=2;i<help.size();i++) if(help[i-2]==first&&help[i-1]==second) ans.push_back(help[i]);
        return ans;
    }
};