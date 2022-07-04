class Solution {
public:
    string evaluate(string a, vector<vector<string>>& w) {
        
        unordered_map<string,string> m;
        for(int i=0;i<w.size();i++)
        {
            m[w[i][0]] = w[i][1];
        }
        
        string ans,h;
        int f=-1;
        for(int i=0;i<a.size();i++)
        {
            if(f==-1)
            {
                if(a[i]!='(')
                    ans.push_back(a[i]);
                else
                    f= i;
            }
            else
            {
                if(a[i]==')')
                {
                    h = a.substr(f+1,i-f-1);
                    f=-1;
                    if(m.count(h))
                        ans+=m[h];
                    else
                        ans.push_back('?');
                }
            }
            // cout<<f<<' ';
                
        }
        
        return ans;
        
        
    }
};