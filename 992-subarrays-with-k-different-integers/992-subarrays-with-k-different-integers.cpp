class Solution {
public:
    int subarraysWithKDistinct(vector<int>& a, int k) {
        
        list<int> q;
        unordered_map<int,int> v;
        unordered_map<int,list<int> ::iterator> m;
        int n = a.size() , start =0 ,i=0,ans=0,h;
        while(m.size()!=k&&i<n)
        {
            q.push_back(i);
            auto it = q.end();
            it--;
            if(m.count(a[i]))
            {
                auto ij = m[a[i]];
                q.erase(ij);
            }
            m[a[i]] = it;
            v[a[i]]++;
            i++;
        }
        if(m.size()!=k)
            return 0;
        ans += (q.front()-start+1);
        // cout<<i<<" "<<st<<" "<<ans<<" "<<q.front()<<endl;
        while(i<n)
        {
            q.push_back(i);
            auto it = q.end();
            it--;
            if(m.count(a[i]))
            {
                auto ij = m[a[i]];
                q.erase(ij);
            }
            else
            {
                h = q.front();
                q.pop_front();
                m.erase(a[h]);
            }
            m[a[i]] = it;
            v[a[i]]++;
            while(v.size()>k)
            {
                v[a[start]]--;
                if(v[a[start]]==0)
                    v.erase(a[start]);
                start++;
            }
            ans += q.front()-start+1;
            // cout<<i<<" "<<st<<" "<<ans<<" "<<q.front()<<endl;
            i++;
        }
        return ans;
        
    }
};

/*

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& a, int k) {
        
        int n = a.size();
        int st =0 , f=0 , s =0 ,i=1,ans=0;
        unordered_map<int,int> m;
        m[a[0]]++;
        while(i<n)
        {
            m[a[i]]++;
            if(a[i]==a[i-1])
                f = i;
            else
            {
                s= f;
                f = i;
            }
            while(m.size()>2)
            {
                m[a[st]]--;
                if(m[a[st]]==0)
                    m.erase(a[st]);
                st++;
            }
            if(m.size()==2)
                ans += (s-st+1);
            i++;
        }
        return ans;
        
    }
};

*/