class Solution {
public:
    int maxTurbulenceSize(vector<int>& a) {
        int n = a.size(),f=0,ans =0 ,c=1;
        if(n==1) return 1;
        for(int i=1;i<n;i++){
            if(a[i]==a[i-1]){ans = max(ans,c);c=1;f=0;}
            else{
                if(a[i]>a[i-1]){
                    if(f==1||f==0){c++;f=-1;}
                    else{ans = max(ans,c);c=2;  }
                }
                else{
                    if(f==-1||f==0){c++;f=1;}
                    else{ans= max(ans,c);c=2;}
                }
            }
        }
        ans = max(ans,c);
        return ans;
    }
};