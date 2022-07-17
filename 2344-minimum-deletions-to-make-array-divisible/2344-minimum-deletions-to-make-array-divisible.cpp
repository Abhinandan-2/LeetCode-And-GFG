class Solution {
public:
    int minOperations(vector<int>& a, vector<int>& b) {
    
        
        int  gcd = b[0];
        
        for(int i=1;i<b.size();i++)     // Finding smallest number(gcd) which divide the numDivide array
            gcd  = __gcd(gcd,b[i]);
        
        vector<int> v;
        
        for(int i=1;i<=sqrt(gcd);i++)    // Finding all divisor of smallest number(gcd)
        {
            if(gcd%i==0)
            {
                v.push_back(i);
                if(gcd/i!=i)
                {
                    v.push_back(gcd/i);
                }
            }
            
        }
        
       // It’s time to find the smallest number which is present in both divisor and nums array 

        sort(v.begin(),v.end());   // First sort both array
        sort(a.begin(),a.end());
        
        
        int i=0 , j=0;
        int n = a.size() , m = v.size() ,ans =-1;
        while(i<n&&j<m)
        {
            if(a[i]==v[j])     // If found put index in nums of that element iin ans variable
            {
                ans = i;        
                break;
            }
            if(a[i]<v[j])
                i++;
            else
                j++;
        }

               return ans;
        
    }
};
