class Solution {
    
    vector<string> genStrings(string &a)
    {
        int n= a.size();
        vector<string> ans;
        string h,k,res;
        for(int i=1;i<n;i++)
        {
            h = a.substr(0,i);
            k = a.substr(i,n-i);
            if(i!=1&&h[0]=='0')
                continue;
            if(k[n-1-i]=='0')
                continue;
            res = h;
            res +=".";
            res += k;
            ans.push_back(res);
        }
        if(n==1)
            ans.push_back(a);
        else if(a[0]!='0')
            ans.push_back(a);
            
        return ans;
    }
    
public:
    vector<string> ambiguousCoordinates(string a) {
        
        a.pop_back();
        a.erase(a.begin());
        int n = a.size();
        if(n==1)
            return {};
        vector<string> left,right,ans;
        string help,st,h,k;
        for(int i=1;i<n;i++)
        {
            h = a.substr(0,i);
            k = a.substr(i,n-i);
            left = genStrings(h);
            right = genStrings(k);
            if(left.size()==0||right.size()==0)
                continue;
            for(int j=0;j<left.size();j++)
            {
                st += "(";
                st += left[j];
                st += ", ";
                for(int k=0;k<right.size();k++)
                {
                    help = st;
                    help += right[k];
                    help += ")";
                    ans.push_back(help);
                }
                st.clear();
            }
        }
        
        return ans;
        
        
    }
};