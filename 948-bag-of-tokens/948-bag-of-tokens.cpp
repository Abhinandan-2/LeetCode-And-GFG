class Solution {
public:
    int bagOfTokensScore(vector<int>& a, int power) {
        
        int n = a.size();
        
        sort(a.begin(),a.end());
        
        int i=0 ,j =n-1,ans =0 ,score =0 ;
        
        while(i<=j)
        {
            if(power>=a[i])
            {
                score++;
                power-=a[i];
                i++;
            }
            else
            {
                if(score==0)
                    return ans;
                score--;
                power+=a[j];
                j--;
            }
            ans= max(ans,score);
        }
        return ans;
        
    }
};