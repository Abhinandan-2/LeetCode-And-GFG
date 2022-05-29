class Solution {
public:
    string discountPrices(string a, int dis) {
        
        int n = a.size() , f = 0;
        vector<string> v;
        string h;
        dis = (double)100-dis;
        double res;
        for(int i=1;i<n;i++)
        {
            if(a[i]==' ')
            {
                h = a.substr(f,i-f);
                f = i+1;
                v.push_back(h);
            }
        }
        h = a.substr(f,n-f);
        v.push_back(h);
        long long ans1 =0;
        string ans,k;
        for(int i=0;i<v.size();i++)
        {
            
            if(v[i][0]!='$'||v[i].size()==1)
                ans += v[i];
            else
            {
                f =0;
                ans1 =0;
                for(int j=1;j<v[i].size();j++)
                {
                    if(!(v[i][j]>=48&&v[i][j]<=57))
                    {
                        f=1;
                        break;
                    }
                    else
                    {
                        ans1 *= 10;
                        ans1 += v[i][j]-48;
                    }
                    
                }
                if(f==1)
                    ans += v[i];
                else
                {
                    k.clear();
                    ans += "$";
                    res = ans1*dis;
                    
                    if(res==0.0)
                    {
                        ans += "0.00";
                    }
                    else{
                        long long dec = res;
                        k = to_string(dec);
                        if(k.size()<3)
                            k.insert(k.begin(),'0');
                        int k1 = k.size();
                        k.insert(k.begin()+k1-2,'.');
                        if(k[0]=='.')
                            k.insert(k.begin(),'0');
                        ans += k;
                }
                }
            }
            ans += " ";
        }
        ans.pop_back();
        return ans;
        
        
        
    }
};