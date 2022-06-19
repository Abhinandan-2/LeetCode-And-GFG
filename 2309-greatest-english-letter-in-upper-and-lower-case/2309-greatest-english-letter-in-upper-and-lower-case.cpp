class Solution {
public:
    string greatestLetter(string a) {
        
        int n = a.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        {
            if(isupper(a[i]))
                m[a[i]]++;
        }
        char ans = (char)90;
        for(int i=0;i<n;i++)
        {
            if(islower(a[i]))
            {
                if(m.count(a[i]-32))
                {
                    ans = max(ans,a[i]);
                }
            }
        }
        
        if(ans==90)
            return "";
        string res;
        res.push_back(ans-32);
        return res;
        
        
    }
};