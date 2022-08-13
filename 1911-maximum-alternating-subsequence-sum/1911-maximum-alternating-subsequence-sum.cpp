#define ll long long

class Solution {
public:
    long long maxAlternatingSum(vector<int>& a) {
        
        ll n= a.size() , flag  =0, ans =0,last ; 
		// flag = 0 -> In search of local max
		// flag = 1 -> In search of local min
		// last -> What is the last value added or subtracted in ans
        ans = a[0];
		last = a[0];
        for(int i=1;i<n;i++)
        {
            if(a[i]==a[i-1])       // If same value no need to do anything beacuse it will not help in finding local max or local min
                continue;
            if(flag==0)             // In search of local max
            {
                if(a[i]>last)          // If cur value greater than last value it means last is not the local max and cur shoud be local max
                {
                    ans-=last;          // Sub last and Add Cur value
                    ans+= a[i];
                    last = a[i];
                }
                else                       // It means last is local max and cur should be local min
                {
                    ans -= a[i];        // Local min -> Sub from ans
                    last=a[i];
                    flag=1;            // Turn flag 1 beacuase now we will in search of local min
                } 
            }
            else                   // In search of local min
            {
                if(a[i]<last)           //  If cur value less than last value it means last is not the local min and cur shoud be local min
                {
                    ans +=last;    // Add last and Sub Cur value
                    ans -= a[i];
                    last = a[i];
                }
                else              // It means last is local min and cur should be local max
                {
                    ans += a[i];   // Local max -> Add in ans
                    last = a[i];
                    flag=0;          // Turn flag 0 beacuase now we will in search of local max
                }
            }
        }
        
        if(flag==1)            // If last value is for local min, no need to Sub from ans. So, Add it in ans to maxmize the answer
            ans += last;
        return ans;
        
        
    }
};