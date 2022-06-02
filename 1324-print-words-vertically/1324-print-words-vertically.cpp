class Solution {
public:
    vector<string> printVertically(string a) {
        
        vector<string> v,ans;
        stringstream c(a);
        string h;
        while(getline(c,h,' '))
            v.push_back(h);
        int mx =0 ,k;
        for(auto i:v)
        {
            k = i.size();
            mx = max(mx,k);
        }
        
        for(int j=0;j<mx;j++)
        {
            h.clear();
            for(int i=0;i<v.size();i++)
            {
                if(j>=v[i].size())
                    h.push_back(' ');
                else
                    h.push_back(v[i][j]);
            }
            while(h.size()>0&&h.back()==' ')
                h.pop_back();
            ans.push_back(h);
        }
        return ans;
        
        
    }
};