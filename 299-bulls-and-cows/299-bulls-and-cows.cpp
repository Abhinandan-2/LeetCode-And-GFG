class Solution {
public:
    string getHint(string a, string b) {
        
        int n = a.size() , bull=0 , cow =0 ;
        unordered_map<char,int> m;
        for(int i=0;i<n;i++)
        {
            if(a[i]==b[i])
                bull++;
            else
                m[a[i]]++;
        }
        
        for(int i=0;i<n;i++)
        {
            if(a[i]!=b[i])
            {
                if(m.count(b[i]))
                {
                    cow++;
                    m[b[i]]--;
                    if(m[b[i]]==0)
                        m.erase(b[i]);
                }
            }
        }
        
        string ans ;
        ans += to_string(bull);
        ans += "A";
        ans += to_string(cow);
        ans += "B";
        return ans;
         
        
    }
};