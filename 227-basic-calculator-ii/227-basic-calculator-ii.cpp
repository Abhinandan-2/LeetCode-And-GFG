class Solution {
    
    
    void solve(vector<int> &nums,int op,int po)
    {
        
        vector<int> ans;
        int h;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=op&&nums[i]!=po)
                ans.push_back(nums[i]);
            else
            {
                h = ans.back();
                ans.pop_back();
                if(nums[i]==op)
                {
                    if(op==-1)
                        h /= nums[i+1];
                    else
                        h -= nums[i+1];
                }
                else
                {
                    if(po==-2)
                        h *= nums[i+1];
                    else
                        h += nums[i+1];
                }
                ans.push_back(h);
                i++;
            }
        }
        
        nums = ans;
        return ;
    }
    
    
public:
    int calculate(string a) {
        
        int n = a.size() , h = 0 ;
        
        vector<int> nums;
       
        
        for(int i=0;i<n;i++)
        {
            if(a[i]>=48&&a[i]<=57)
            {
                h *= 10;
                h += (a[i]-48);
            }
            else if(a[i]!=' ')
            {
                nums.push_back(h);
                h=0;
                if(a[i]=='/')
                    nums.push_back(-1);
                else if(a[i]=='*')
                    nums.push_back(-2);
                else if(a[i]=='-')
                    nums.push_back(-3);
                else
                    nums.push_back(-4);
            }
        }
        nums.push_back(h);
        // for(auto i:nums)
        //     cout<<i<<" ";
        // cout<<endl;
        solve(nums,-1,-2);
        // for(auto i:nums)
        //     cout<<i<<" ";
        // cout<<endl;
        solve(nums,-3,-4);
        
        return nums[0];
        
    }
};