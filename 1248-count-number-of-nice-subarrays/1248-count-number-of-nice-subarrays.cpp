class Solution {
public:
    int numberOfSubarrays(vector<int>& a, int k) {
        
        int n=a.size(),ans =0 , i=0 , j= -1 ,f=0,s=0;
        
        while(i<n)
        {
            if(a[i]%2!=0)
                s++;
            if(s==k)
                break;
            i++;
        }
        if(s!=k)
            return 0;
        while(i<n)
        {
            s=0;
            f=0;
            j++;
            f++;
            while(a[j]%2==0)
            {
                j++;
                f++;
            }
            i++;
            s++;
            while(i<n&&a[i]%2==0)
            {
                i++;
                s++;
            }
            // cout<<i<<" "<<j<<" "<<f<<" "<<s<<endl;
            ans += f*s;
        }
        return ans;
        
        
    }
};