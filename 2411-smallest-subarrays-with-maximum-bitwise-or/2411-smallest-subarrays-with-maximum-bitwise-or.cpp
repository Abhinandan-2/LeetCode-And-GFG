class Solution {   
    bool performTask(vector<int> &count,int num,int task){
        int i=0,ans =1;
        while(num){
            if(num%2!=0){
                if(task==1) count[i]++;
                else if(task==2) {if(count[i]==0) ans =0;}
                else count[i]--;
            }
            num/=2;
            i++;
        }
        return ans;
    }
public:
    vector<int> smallestSubarrays(vector<int>& a) {
        int n = a.size(),i=0,j=0;
        vector<int> bitOr(n),count(32,0),ans(n);
        bitOr[n-1] = a[n-1];
        for(int i=n-2;i>=0;i--) bitOr[i] = a[i]|bitOr[i+1];
        while(i<n){
            performTask(count,a[i],1);
            while(j<=i&&performTask(count,bitOr[j],2)){
                ans[j] = i-j+1;
                performTask(count,a[j],3);
                j++;
            }
            i++;
        }
        return ans; 
    }
};