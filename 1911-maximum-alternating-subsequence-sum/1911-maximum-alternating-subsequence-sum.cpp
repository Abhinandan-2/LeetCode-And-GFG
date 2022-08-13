#define ll long long

class Solution {
public:
    long long maxAlternatingSum(vector<int>& a) {
        
        ll flag  =0, ans =0,last ; 
		// flag = 0 -> In search of local max
		// flag = 1 -> In search of local min
		// last -> What was the most recent value added or subtracted from ans
        ans = a[0];
		last = a[0];
        for(int i=1;i<a.size();i++){
            if(a[i]==a[i-1])       // If the values are the same, there is no need to do anything because it will not help in determining the local maximum or minimum.
                continue;
            if(flag==0){             // In search of local max{
                if(a[i]>last){         // If cur is greater than last, it means that last is not the local maximum and cur should be.
                    ans-=last;          // Sub last and Add Cur value
                    ans+= a[i];
                    last = a[i];
                }
                else{                       // It means last is local max and cur should be local min
                    ans -= a[i];        // Local min -> Sub from ans
                    last=a[i];
                    flag=1;            // Turn flag 1 because now we will be in search of local min.
                } 
            }
            else{                   // In search of local min
                if(a[i]<last){           //  If cur is less than the last value, it means last is not the local min and cur should be the local min.
                    ans +=last;    // Add last and sub cur value
                    ans -= a[i];
                    last = a[i];
                }
                else{              // It means last is local min and cur should be local max
                    ans += a[i];   // Local max -> Add in ans
                    last = a[i];
                    flag=0;          // Turn flag 0 because we will now be looking for local max.
                }
            }
        }
        
        if(flag==1)     // If the last value is for the local minimum, there is no need to sub from ans. So, add it in answer to maximise the answer.       
            ans += last;
        return ans; 
    }
};