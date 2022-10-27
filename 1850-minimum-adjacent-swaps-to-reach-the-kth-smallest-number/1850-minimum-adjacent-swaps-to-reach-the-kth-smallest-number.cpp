class Solution {
public:
    void change(string &a){
        int n = a.size(),f,g;
        char mx = a[n-1],mn='a';
        for(int i=n-2;i>=0;i--){
            if(a[i]<mx) {f=i;break;}
            else mx = a[i];
        }
        for(int i=f+1;i<n;i++){
            if(a[i]>a[f]){
                if(a[i]<mn) {g=i;mn=a[i];}
            }
        }
        swap(a[f],a[g]);
        sort(a.begin()+f+1,a.end());
        return ;
    }
    
    int getMinSwaps(string a, int k) {
        
        int n = a.size();
        string res = a;
        while(k--) change(a);
        int ans =0,f ;
        for(int i=0;i<n;i++){
            if(a[i]!=res[i]){
                for(int j=i;j<n;j++){
                    if(a[j]==res[i]) {f=j;break;}
                }
                while(f!=i){
                    swap(a[f],a[f-1]);
                    f--;
                    ans++;
                }
            }
        }
        return ans;
    }
};