class Solution {
    
    int call(vector<int> &a,vector<int> &b)
    {
        int n = a.size() , m = b.size(),ans=0,res=0,f,s;
        unordered_map<int,int> ma,mb;
        for(auto i:b)
            mb[i]++;
        for(auto i:a)
            ma[i]++;
        long long sq;
        for(auto i:ma)
        {
            f = i.first;
            s = i.second;
            sq = (long long)f*f;
            res =0 ;
            for(int j=1;j<=f;j++)
            {
                if(sq%(long long)j==0)
                {
                    if(j!=f)
                        res += (mb[j]*mb[(int)(sq/(long long)j)]);
                    else
                        res += ((mb[j]*(mb[j]-1))/2);
                }
            }
            ans += res*s;
        }
        return ans;
    }
    
public:
    int numTriplets(vector<int>& a, vector<int>& b) {
        
        int ans1 = call(a,b);
        int ans2 = call(b,a);
        return ans1+ans2;
        
    }
};