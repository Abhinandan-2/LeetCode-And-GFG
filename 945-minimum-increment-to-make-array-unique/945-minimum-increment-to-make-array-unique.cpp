class Solution {
public:
    int minIncrementForUnique(vector<int>& a) {
        
        int n = a.size() , m1 = *max_element(a.begin(),a.end());
        unordered_map<int,int> m;
        queue<int> q;
        int ans = 0 , back =0 ,k;
        for(auto i:a)
            m[i]++;
        
        for(int i=0;i<=m1;i++)
        {
            if(!m.count(i))
            {
                if(!q.empty())
                {
                    ans += (i-q.front());
                    q.pop();
                }
            }
            else
            {
                k = m[i];
                k--;
                while(k--)
                    q.push(i);
            }
        }
        
        int i = m1+1;
        while(!q.empty())
        {
            ans += (i-q.front());
            q.pop();
            i++;
        }
        
        return ans;
        
    }
};