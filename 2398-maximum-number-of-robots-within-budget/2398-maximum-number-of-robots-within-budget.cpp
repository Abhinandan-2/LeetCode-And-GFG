class Solution {
public:
    int maximumRobots(vector<int>& time, vector<int>& cost, long long tar) {
        
        int i =0, j=0 , n = cost.size(),ans=0;
        long long sum=0,curCost;
        multiset<int> s;
        while(i<n)
        {
            sum += cost[i];
            s.insert(time[i]);
            curCost = (i-j+1)*sum+*s.rbegin();
            while(j<=i&&curCost>tar)
            {
                sum -= cost[j];
                auto it = s.find(time[j]);
                s.erase(it);
                j++;
                if(j>i) curCost =0 ;
                else curCost = (i-j+1)*sum+*s.rbegin();
            }
            ans = max(ans,i-j+1);
            i++;
        }
        return ans;
    }
};