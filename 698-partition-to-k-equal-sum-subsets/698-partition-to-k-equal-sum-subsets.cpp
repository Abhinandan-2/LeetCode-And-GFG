class Solution {
    
    bool isEqual(vector<int> &a,int t)
    {
        for(auto i:a)
            if(i!=t)
                return 0;
        return 1;
    }
    
    bool fillLen(vector<int> &a,int i,int t,vector<int> &len)
    {
        int n = a.size();
        if(isEqual(len,t))
            return 1;
        int m = len.size(),k;
        for(int j=0;j<m;j++)
        {
            k = j-1;
            while(k>=0)
            {
                if(len[j]==len[k])
                    break;
                k--;
            }
            if(k!=-1)
                continue;
            if(len[j]+a[i]<=t)
            {
                len[j] += a[i];
                if(fillLen(a,i+1,t,len))
                    return 1;
                len[j] -= a[i];
            }
        }
        return 0;
    }
    
public:
    bool canPartitionKSubsets(vector<int>& a, int k) {
        
        int sum = accumulate(a.begin(),a.end(),0);
        if(sum%k!=0)      
            return 0;
        int t = sum/k;
        sort(a.begin(),a.end(),greater<int>());
        if(a[0]>t)
            return 0;
        vector<int> len(k,0);
        return fillLen(a,0,t,len);
        
    }
};