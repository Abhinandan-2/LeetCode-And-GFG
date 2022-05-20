class Solution {
public:
    bool queryString(string a, int t) {
        
        if(t>5005003)
            return 0;
        int n = a.size();
        unordered_map<int,int> m;
        long long sum =0;
        for(int i=n-1;i>=0;i--)
        {
            sum=0;
            for(int j=i;j<min(i+32,n);j++)
            {
                sum*=2;
                if(a[j]=='1')
                    sum++;
                if(sum<INT_MAX)
                m[(int)sum]++;
                //cout<<sum<<endl;
            }
        }
        
        for(int i=1;i<=t;i++)
        {
            if(!m.count(i))
                return 0;
        }
        return 1;
        
        
        
    }
};