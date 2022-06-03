class Solution {
public:
    
//     string call(string a,string b)
//     {
//         int n = a.size() , m = b.size();
        
//         int i=0,j=0;
        
//         while(i<n&&j<m)
//         {
//             if(a[i]<b[i])
//                 return b;
//             if(a[i]>b[i])
//                 return a;
//             i++;
//             j++;
//         }
//         if(i==n)
//             return b;
//         return a;
        
//     }
    
    string largestWordCount(vector<string>& a, vector<string>& b) {
        
        int n = a.size();
        unordered_map<string,int> m;
        string p,h;
        int c1;
        for(int i=0;i<n;i++)
        {
            c1=0;
            p = a[i];
            stringstream c(p);
            while(getline(c,h,' '))
                c1++;
            m[b[i]] += c1;
        }
        string ans;
        int mx =0 ;
        for(auto i:m)
        {
            if(i.second>=mx)
            {
                if(i.second>mx)
                {
                    ans = i.first;
                }
                mx = i.second;
                ans = max(i.first,ans);
            }
        }
        
        return ans;
        
        
        
    }
};