class Solution {
    
    vector<int> makeLsp(string &a){
        int n = a.size(),i =1 , len =0 ;
        vector<int> ans(n,0);
        while(i<n){
            if(a[len]==a[i]) ans[i++] = ++len;  
            else{
                if(len!=0) len = ans[len-1];
                else ans[i++] = 0;
            }
        }
        return ans;
    }
    
    int isSub(string &a,string &b,vector<int> &va){
        int n = a.size(),m=b.size(),i=0,j=0;
        while(i<n&&j<m){
            if(a[i]==b[j]){i++;j++;}
            else{
                if(i!=0) i = va[i-1];
                else j++;
            }
        }
        if(i==n) return j-n;
        return -1;
    }
    
    bool check(string &a,string &b,vector<int> &vb){
        int n = a.size(), m = b.size(),i=0,len=0;
        vector<int> ans(n,0);
        while(i<n) a[i]==b[len] ? ans[i++] = ++len : ( len!=0 ? len = vb[len-1]:ans[i++] = 0 );
        if(ans[n-1]==0) return 0;
        int back = n-1-ans[n-1],h =m-1;
        while(back>=0) if(a[back--]!=b[h--]) return 0;
        return 1;
    }
    
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.size() , m = b.size(),pos,h,f,ans=0,savePos;
        string k;
        vector<int> va = makeLsp(a),vb=makeLsp(b);
        if(m<=n){
            pos = isSub(b,a,vb);
            if(pos!=-1) return 1;
            if(check(b,a,va)) return 2;
            return -1;
        }
        pos = isSub(a,b,va);
        if(pos==-1){
            if(m>=2*n-1) return -1;
            if(check(b,a,va)) return 2;
            return -1;
        }
        savePos = pos-1;h=0;f=0;
        while(pos<=m-n){
            k = b.substr(pos,n);
            if(k!=a) return -1;
            pos += n;ans++;
        }
        while(pos<m){
            if(a[h++]!=b[pos++]) return -1;
            if(f==0){ans++;f++;}
        }
        h = n-1;f=0;
        while(savePos>=0){
            if(a[h--]!=b[savePos--]) return -1;
            if(f==0){ans++;f=1;}
        }
        return ans;
    }
};