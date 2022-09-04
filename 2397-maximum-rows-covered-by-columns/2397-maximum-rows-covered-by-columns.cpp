class Solution {
    void call(vector<vector<int>> &a,int t,int &ans,unordered_map<int,int> &mp,int i){
        int n = a.size() , m = a[0].size();
        if(t==0){
            int cur =0,f;
            for(int i=0;i<n;i++){
                f=0;
                for(int j=0;j<m;j++) if(a[i][j]==1&&mp[j]==0){f=1;break;}
                if(f==0) cur++;
            }
            ans = max(ans,cur);
            return ;
        }
        for(int j=i;j<=m-t;j++){
            mp[j]++;
            call(a,t-1,ans,mp,j+1);
            mp[j]--;
        }
        return ; 
    }
public:
    int maximumRows(vector<vector<int>>& a, int t) {
        int ans = 0 ;
        unordered_map<int,int> mp;
        call(a,t,ans,mp,0);
        return ans;
    }
};