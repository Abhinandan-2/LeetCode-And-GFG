#define ll long long

class Solution {
public:
    long long maxAlternatingSum(vector<int>& a) {
        
        ll n= a.size() , flag  =0, ans =0, val = a[0], cur ;
        // flag = 0 -> In search of local max
		// flag = 1 -> In search of local min
        for(int i=1;i<n;i++)
        {
            if(a[i]==a[i-1])    // If the values are the same, there is no need to do anything because it will not help in determining the local maximum or minimum.
                continue;
            if(flag==0)        // In search of local max
            {
                if(a[i]>val)     // Maximise the val
                   val = a[i];
                else
                {
                    ans += val;  // Add local max to ans
                    val = a[i];  
                    flag = 1;    // Turn flag 1 because now we will be in search of local min.
                } 
            }
            else                // In search of local min
            {
                if(a[i]<val)    // Minimise the val
                    val = a[i];
                else
                {
                    ans -= val; // Sub from ans
                    val = a[i];
                    flag = 0;   // Turn flag 0 because we will now be looking for local max.
                }
            }
        }
        
        if(flag==0)           // If last search for local max then add it to ans
            ans += val;
        return ans;
    }
};