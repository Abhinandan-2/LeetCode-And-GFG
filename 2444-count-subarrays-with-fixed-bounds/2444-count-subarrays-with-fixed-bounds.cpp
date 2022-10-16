class Solution {
public:
    long long countSubarrays(vector<int>& a, int minK, int maxK) { 
        int n = a.size(),start = -1 , left =-1, right =-1 , curMx = INT_MIN, curMn = INT_MAX, flag=0 , curLen =0 ;
        // start -> First element that might be the part of fixed-bound subaaray
        // left -> Last element that is equal to minK after start
        // right -> Last elemetn that is equal to maxK after start
        // curMx -> max value after start
        // curMn -> min value after start
        // flag -> Used for initializing start
        // curLen -> Length from start to left or right depend upon cur value of element
        long long ans =0;
        for(int i=0;i<n;i++){
            curMx = max(curMx,a[i]);       
            curMn = min(curMn,a[i]);       
            if(flag==0&&a[i]>=minK&&a[i]<=maxK){
                start = i;
                flag=1;
            }
			if(a[i]==minK) left = i;
            if(a[i]==maxK) right = i;
            if(curMx==maxK&&curMn==minK){
                if(a[i]==maxK) curLen = (left-start+1);        // If cur element if maxK then curLen is from start to left
                else  if(a[i]==minK) curLen = (right-start+1); // Else if cur element if maxK then curLen is from start to right
                ans+= curLen;                                  // Otherwise no change in curLen
            }
            else if(curMx>maxK||curMn<minK){      // If cur element is greater than maxK or less than minK then it will not be part of subarray so reset all values
                curMx = INT_MIN;
                curMn = INT_MAX;
                start =-1;
                left = -1;
                right = -1;
                curLen = 0;
                flag =0;
            }
        }
        return ans;
    }
};