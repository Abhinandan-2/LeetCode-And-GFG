class Solution {
public:
    int sumFourDivisors(vector<int>& a) {
        int ans= 0,sum =0, count,n = a.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            if(m.count(a[i])){ans += m[a[i]];continue;}
            count =0;sum =0;
            for(int j=1;j<=sqrt(a[i]);j++){
                if(a[i]%j==0){
                    sum += j;count++;
                    if(a[i]/j!=j){sum += a[i]/j;count++;}
                }
            }
            if(count==4) m[a[i]]=sum;
            else m[a[i]] =0;
            ans += m[a[i]];
        }
        return ans;
    }
};