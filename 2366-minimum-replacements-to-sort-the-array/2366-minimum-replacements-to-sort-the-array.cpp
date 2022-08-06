#define ll long long 

class Solution {
public:
    long long minimumReplacement(vector<int>& num) {
        
        int len = num.size(), right = num[len-1];
        ll res =0 , brk ;
        if(len==1)
            return 0;
        for(int i=len-2;i>=0;i--){
            if(right>=num[i])
                right = num[i];
            else{
                brk = ((num[i]-1)/right)+1;
                right = num[i]/brk;
                res +=(brk-1);
            }       
        }
        return res;    
    }
};