class Solution {
public:
    string replaceWords(vector<string>& a, string b) {
        
        vector<string> word;
        stringstream c(b);
        string help;
        while(getline(c,help,' '))
            word.push_back(help);
        
        string ans;
        int f;
        string h;
        unordered_map<string,int> m;
        for(auto i:a)
            m[i]++;
        int n = word.size(),k;
        for(int i=0;i<n;i++)
        {
            h.clear();
            f=0;
            k = word[i].size();
            for(int j=0;j<min(k,101);j++)
            {
                h.push_back(word[i][j]);
                if(m.count(h))
                {
                    f=1;
                    ans += h;
                    if(i!=n-1)
                        ans += " ";
                    break;
                }
            }
            if(f==0)
            {
                ans += word[i];
                if(i!=n-1)
                    ans += " ";
                    
            }
        }
        return ans;
        
        
        
        
    }
};