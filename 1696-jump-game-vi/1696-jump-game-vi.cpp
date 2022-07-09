class Solution {
public:
    int maxResult(vector<int>& a, int k) {
        
        int n = a.size();
        if(k==1)
            return accumulate(a.begin(),a.end(),0);
        int curmx;
        list<int> q;
        vector<int> mx(n);
        
        mx[0] = a[0];
        q.push_back(0);
        
        for(int i=1;i<n;i++)
        {
            curmx = q.front();
            while(abs(i-curmx)>k){
                q.pop_front();
                curmx = q.front(); 
            }
            mx[i] = a[i]+mx[curmx];
            while(!q.empty()&&mx[q.back()]<=mx[i])
                q.pop_back();
            q.push_back(i);
        }
        // for(auto i:mx)
        //     cout<<i<<" ";
        return mx[n-1];
        
    }
};