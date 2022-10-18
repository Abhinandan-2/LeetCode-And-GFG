class Solution {
public:
    
    bool call(vector<int> &ans,int i,int n,unordered_map<int,int> &m){
        // cout<<i<<"->";
        // for(auto k:ans) cout<<k<<" ";
        // cout<<endl;
        int sz = ans.size();
        if(i>=sz) return 1;
        if(ans[i]!=0) {
            if(call(ans,i+1,n,m)) 
            {
        //         cout<<i<<"->";
        //         for(auto k:ans) cout<<k<<" ";
        // cout<<endl;
                return 1;
            }
        //     cout<<i<<"->";
        //     for(auto k:ans) cout<<k<<" ";
        // cout<<endl;
            return 0;
        }
        for(int j=n;j>=1;j--){
            if(m[j]==0&&(j==1||(i+j<sz&&ans[i+j]==0))){
                ans[i] = j;
                if(j!=1) ans[i+j] = j;
                m[j] = 1;
                if(call(ans,i+1,n,m)){
        //              cout<<i<<"->";
        //     for(auto k:ans) cout<<k<<" ";
        // cout<<endl;
                    return 1;
                }
                m[j]=0;
                ans[i] =0 ;
                if(j!=1) ans[i+j] =0 ;
            }
        }
        //  cout<<i<<"->";
        //     for(auto k:ans) cout<<k<<" ";
        // cout<<endl;
        return 0;
    }
    
    vector<int> constructDistancedSequence(int n) {
       
        int sz = n*2-1;
        vector<int> ans(sz,0);
        unordered_map<int,int> m;
        call(ans,0,n,m);
        return ans;
    }
};