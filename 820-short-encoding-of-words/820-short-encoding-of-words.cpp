class Solution {
public:
    
    static bool com(string &a,string &b)
    {
        int n = a.size() , m = b.size();
        return m<n;
    }
    
    int minimumLengthEncoding(vector<string>& a) {
        
        unordered_map<string,int> m;
        sort(a.begin(),a.end(),com);
        int n = a.size(),ans=0,k;
        string h;
        
        for(int i=0;i<n;i++)
        {
            k = a[i].size();
            if(!m.count(a[i]))
            {
                ans+= k+1;
                for(int j=0;j<k;j++)
                {
                    h = a[i].substr(j,k-j);
                    m[h]++;
                }
            }
                
        }
        
        return ans;
        
        
        
    }
};