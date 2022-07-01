class Solution {
public:
    int totalHammingDistance(vector<int>& a) {
        
        int n = a.size();
        int ans =0 ,even =0 ,odd =0;
        
        for(int j=0;j<32;j++)
        {
            even=0;
            odd=0;
            for(int i=0;i<n;i++)
            {
                if(a[i]%2==0)
                    even++;
                else
                    odd++;
                a[i]=a[i]>>1;
            }
            // cout<<even<<" "<<odd<<endl;
            ans += (even*odd);
        }
        return ans;
        
        
        
    }
};