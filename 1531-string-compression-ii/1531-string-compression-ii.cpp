// We can restrict last dimension to 10, because, m > 10 doesn't change the length of encoded string since n < 100.

// state: index, remain k, last char, concat number

int f[105][105][30][15];

class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        this->s = s;
        
        const int N = s.size();
        if (N == 100 && k == 0) {
            bool allSame = true;
            for (int i = 1; i < N; i++) {
                if (s[i] != s[i - 1]) {
                    allSame = false;
                    break;
                }
            }

            if (allSame) {
                return 4;
            }
        }
        
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= N; j++) {
                for (int k = 0; k <= 26; k++) {
                    for (int m = 0; m <= 10; m++) {
                        f[i][j][k][m] = -1;
                    }
                }
            }
        }
        
        return dfs(0, k, 26, 0);
    }
private:
    string s;
    int dfs(int idx, int k, int last, int concat) {
        if (k < 0) return 9999999;
        if (idx == s.size()) return 0;
        
        int& val = f[idx][k][last][concat];
        if (val != -1) return val;
        
        int answer = 9999999;
		// delete
        answer = min(answer, dfs(idx + 1, k - 1, last, concat));
        // concat
        if (last == s[idx] - 'a') {
            const int fac = (concat == 1 || concat == 9) ? 1 : 0;
            answer = min(answer, fac + dfs(idx + 1, k, last, min(10, concat + 1)));
        } else {
            answer = min(answer, 1 + dfs(idx + 1, k, s[idx] - 'a', 1));
        }
        return val = answer;
    }
};
/*

class Solution {
    
    pair<char,pair<int,int>> giveComp(string &a,int i){
        char ch;
        int curCount =1,count , len =0 ,f=0, n = a.size();
        for(int j=i+1;j<n;j++){
            if(a[j]==a[j-1]) curCount++;
            else{
                if(f==0){
                    ch = a[j-1];
                    count = curCount;
                    f=1;
                }
                if(curCount==1) len+=1;
                else if(curCount>1&&curCount<10) len += 2;
                else if(curCount>=10&&curCount<100) len+= 3;
                else len += 4;
                curCount = 1;
            }
        }
        
        if(f==0){
            ch = a[n-1];
            count = curCount;
        }
        if(curCount==1) len+=1;
        else if(curCount>1&&curCount<10) len += 2;
        else if(curCount>=10&&curCount<100) len+= 3;
        else len += 4;
        // cout<<i<<" "<<ch<<" "<<count<<" "<<len<<endl;
        return {ch,{count,len}};
    }
    
    
    
    vector<pair<char,pair<int,int>>> find(string &a,int k,int i,vector<vector<vector<pair<char,pair<int,int>>>>> &dp){
        int n = a.size() ,count,len;
        cout<<"Pos "<<i<<"Left "<<k<<endl;
        char ch;
        if(i>=n){
            cout<<"Ans "<<i<<" "<<k<<endl;
            cout<<1<<" "<<1<<" "<<0<<endl;
            return {{'1',{1,0}}};
        }
        if(dp[i][k].size()!=0) return dp[i][k];
        vector<pair<char,pair<int,int>>> ans,del,nondel;
        if(k==0){
            ans.push_back(giveComp(a,i));
            dp[i][k]  = ans;
            cout<<"Ans "<<i<<" "<<k<<endl;
            for(auto i:ans) cout<<i.first<<" "<<i.second.first<<" "<<i.second.second<<endl;
            return ans;
        }
        // cout<<i<<";"<<k<<endl;
        nondel = find(a,k,i+1,dp);
        del = find(a,k-1,i+1,dp);
        int mx = 105;
        for(int it=0;it<nondel.size();it++){
            ch = nondel[it].first;
            count = nondel[it].second.first;
            len = nondel[it].second.second;
            if(ch==a[i]){
                if(count==1||count==9||count==99) len++;
                count++;
            }
            else{
                len++;
                ch = a[i];
                count = 1;
            }
            if(len<mx){
                ans.clear();
                mx = len;
                ans.push_back({ch,{count,len}});
            }
            else if(len==mx){
                ans.push_back({ch,{count,len}});
            }
        }
        for(int it=0;it<del.size();it++){
            ch = del[it].first;
            count = del[it].second.first;
            len = del[it].second.second;
            if(len<mx){
                ans.clear();
                mx = len;
                ans.push_back({ch,{count,len}});
            }
            else if(len==mx){
                ans.push_back({ch,{count,len}});
            }
        }
        cout<<"Ans "<<i<<" "<<k<<endl;
        for(auto i:ans) cout<<i.first<<" "<<i.second.first<<" "<<i.second.second<<endl;
        dp[i][k] = ans;
        return ans;
    }
    
public:
    int getLengthOfOptimalCompression(string a, int k) {
        int n = a.size();
        vector<vector<vector<pair<char,pair<int,int>>>>> dp(n,vector<vector<pair<char,pair<int,int>>>> (k+1));
        vector<pair<char,pair<int,int>>> ans = find(a,k,0,dp);
        return ans[0].second.second;
    }
};


class Solution {
    pair<int,int> find(int c){
        pair<int,int> p;
        if(c==1) p = {c,c};
        else if(c>1&&c<10) p= {c-1,c};
        else if(c>9&&c<100) p= {c-9,c};
        else if(c>99) p = {c-99,c};
        return p;
    }
public:
    int getLengthOfOptimalCompression(string a, int k) {
        
        int n = a.size() , c= 1,ans=0,x;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        pair<int,int> p;
        for(int i=1;i<n;i++){
            if(a[i]==a[i-1])
                c++;
            else{
                // p = find(c);
                // cout<<p.first<<" "<<p.second<<endl;
                q.push(find(c));
                c=1;
            }
            if(i==n-1){
                // p = find(c);
                // cout<<p.first<<" "<<p.second<<endl;
                q.push(find(c));
            }
        }
        while(!q.empty()&&k>0){
            p = q.top();
            // cout<<p.first<<" "<<p.second<<endl;
            if(k>=p.first){
                q.pop();
                k -= p.first;
                if(p.second!=1){
                    x =p.second-p.first; 
                    q.push(find(x));
                }
            }
            else{
                k=0;
            }
        }
        while(!q.empty()){
            p = q.top();q.pop();
            if(p.second==1) ans++;
            else if(p.second>1&&p.second<10) ans+=2;
            else if(p.second>9&&p.second<100) ans+=3;
            else if(p.second>99) ans+=3;
        }
        return ans;
        
        
    }
};

*/