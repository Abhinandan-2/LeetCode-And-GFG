class Solution {
public:
    int closestMeetingNode(vector<int>& a, int n1, int n2) {
        
        unordered_map<int,int> m1,m2;
        int n = a.size();
        int i = n1,c=0;
        
        while(i!=-1&&!m1.count(i))
        {
            m1[i] = c;
            c++;
            i = a[i];
        }
        
        i = n2;
        c =0;
        while(i!=-1&&!m2.count(i))
        {
            m2[i] = c;
            c++;
            i = a[i];
        }
        
        int ans = INT_MAX , f =0 ,g =0,res = -1 ;
        
        for(int i=0;i<n;i++)
        {
            if(m1.count(i)&&m2.count(i))
            {
                f = m1[i];
                g= m2[i];
                if(max(f,g)<=ans)
                {
                    if(max(f,g)==ans)
                        res = min(res,i);
                    else
                        res = i;
                    ans = max(f,g);
                }
            }
        }
        
        
        return res;
        
    }
};