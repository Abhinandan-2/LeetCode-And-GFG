class Solution {
public:
    int maximum69Number (int n) {
        
        int ans =0 , f=0;
        vector<int> v;
        while(n){
            v.push_back(n%10);
            n/=10;
        }
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            if(f==0&&v[i]==6){
                v[i]=9;
                f=1;
            }
            ans *= 10;
            ans += v[i];
        }
        return ans;
        
    }
};