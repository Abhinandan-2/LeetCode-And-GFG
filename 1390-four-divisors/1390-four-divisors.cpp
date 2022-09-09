class Solution {
public:
    int sumFourDivisors(vector<int>& a) {
        
        int ans= 0,sum =0, count,num ,n = a.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        {
            if(m.count(a[i])){ans += m[a[i]];continue;}
            num = a[i];
            count =0;
            sum =0;
            for(int j=1;j<=sqrt(num);j++)
            {
                if(num%j==0)
                {
                    sum += j;
                    count++;
                    if(num/j!=j)
                    {
                        sum += num/j;
                        count++;
                    }
                }
            }
            if(count==4) m[num]=sum;
            else m[a[i]] =0;
            ans += m[a[i]];
        }
        
        return ans;
        
    }
};