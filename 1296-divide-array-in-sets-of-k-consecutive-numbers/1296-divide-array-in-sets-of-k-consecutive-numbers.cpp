class Solution {
public:
    bool isPossibleDivide(vector<int>& a, int k) {
        
        int n = a.size();
        int h,p;
        pair<int,int> q;
        if(n%k!=0)
            return 0;
        
        int t = n/k;
        
        map<int,int> m;
        
        for(auto i:a)
            m[i]++;
        
        while(t--)
        {
            q = *m.begin();
            p = q.first;
            h = k;
            while(m.count(p)&&h)
            {
                m[p]--;
                if(m[p]==0)
                    m.erase(p);
                p++;
                h--;
            }
            if(h!=0)
                return 0;
        }
        
        return 1;
        
    }
};