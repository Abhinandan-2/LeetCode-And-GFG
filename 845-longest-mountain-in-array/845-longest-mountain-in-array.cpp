class Solution {
public:
    int longestMountain(vector<int>& a) {
        
        int n = a.size(), flag = 1 , pointer = -1,ans = 0,flag2 =0;
        if(n<3)
            return 0;
        for(int i=1;i<n;i++)
        {
            if(a[i]>a[i-1])
            {
                if(flag==1)
                {
                    if(pointer!=-1)
                    ans = max(ans,i-1-pointer+1);
                    pointer = i-1;
                    flag=0;
                }
                if(flag2==1)
                    flag2=0;
            }
            else if(a[i]<a[i-1])
            {
                if(flag==0)
                    flag=1;
                if(flag2==1)
                {
                    pointer = -1;
                    flag2 = 0;
                }
            }
            else
            {
                if(flag==1)
                {
                    if(pointer!=-1)
                        ans = max(ans,i-1-pointer+1);
                    pointer = i+1;
                }
                else
                {
                    flag =1 ;
                    pointer = i+1;
                }
                flag2 =1;
            }
        }
        if(flag==1&&pointer!=-1)
            ans = max(ans,n-1-pointer+1);
        
        return ans;
        
        
        
    }
};