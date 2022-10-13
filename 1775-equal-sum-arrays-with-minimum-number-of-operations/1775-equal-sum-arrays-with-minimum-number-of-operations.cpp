class Solution {
public:
    int minOperations(vector<int>& a, vector<int>& b) {
        int n = a.size()  , m = b.size(), count = 0,p,sumF, sumS;
        if(n<m) swap(n,m);
        if(m*6<n) return -1;
        
        unordered_map<int,int> first,second;
        
        int sum1 = accumulate(a.begin(),a.end(),0);
        int sum2 = accumulate(b.begin(),b.end(),0);
        if(sum1<sum2) {swap(a,b); swap(sum1,sum2);}
        n = a.size() , m = b.size() , sumF = sum1,sumS = sum2;
        first[sum1] =0 ;
        second[sum2] = 0;
        priority_queue<int> q;
        priority_queue<int,vector<int>,greater<int>> v;
        for(auto i:a) if(i!=1) q.push(i);
        for(auto i:b) if(i!=6) v.push(i);
        while(!q.empty()){
            p = q.top(); q.pop();
            count++;
            while(p>1&&sum1>=sumS){
                sum1--;
                first[sum1] = count;
                p--;
            }
        }
        count = 0;
        while(!v.empty()){
            p = v.top() ; v.pop();
            count++;
            while(p<6&&sum2<=sumF){
                sum2++;
                second[sum2] = count;
                p++;
            }
        }
        
        int ans = INT_MAX;
        
        for(int i=sumF;i>=sumS;i--) if(first.count(i)&&second.count(i)) ans = min(ans,first[i]+second[i]);
        
        return ans;
        
        
    }
};