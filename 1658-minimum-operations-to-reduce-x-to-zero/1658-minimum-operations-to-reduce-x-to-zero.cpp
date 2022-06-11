class Solution {
public:
    int minOperations(vector<int>& a, int x) {
        
        int sum =0 , n = a.size() , f=0 , ans = INT_MAX , j =-1 ,i,h ;
        // cout<<ans<<endl;
        sum = accumulate(a.begin(),a.end(),0);
        if(x>sum)
            return -1;
        if(x==sum)
            return n;
        sum =0;
        for(int i=0;i<n;i++)
        {
            sum += a[i];
            if(sum<x)
                j = i;
            else if(sum==x)
            {
                j=i;
                break;
            }
            else
            {
                sum -= a[i];
                break;
            }
        }
        if(j==-1)
        {
            f=1;
            j =n-1;
            sum=0;
        }
        // cout<<sum<<" "<<ans<<endl;
        if(sum==x)
        ans = min(ans,j+1);
        i = n-1;
        while(1)
        {
            // cout<<ans<<endl;
            sum += a[i];
            // cout<<i<<" "<<j<<" "<<sum<<" "<<f<<endl;
            while(sum>x)
            {
                sum -= a[j];
                j--;
                if(j==-1)
                {
                    
                    j = n-1;
                    f++;
                }
                // cout<<sum<<" "<<j<<" "<<f<<endl;
            } 
            if(f>1)
                break;
            // cout<<ans<<endl;
            if(f==1&&j<n-1)
                break;
            if(sum==x)
            {
                if(f==1)
                    ans = min(ans,j-i+1);
                else
                {
                    h = j+1;
                    h += (n-i);
                    ans = min(ans,h);
                }
            }
            // cout<<ans<<endl;
            i--;
        }
        // cout<<ans;
        if(ans==INT_MAX)
            return -1;
        return ans;
        
    }
};

