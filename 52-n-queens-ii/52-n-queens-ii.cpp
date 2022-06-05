class Solution {
public:
    
    
    bool isValid(vector<string> &a,int x,int y)
    {
        int n = a.size();
        
        for(int i=0;i<n;i++)
            if(i!=x&&a[i][y]=='Q')
                return 0;
        int i=x-1,j =y-1;
        while(i>=0&&j>=0)
        {
            if(a[i][j]=='Q')
                return 0;
            i--;
            j--;
        }
        
        i = x+1;
        j = y+1;
        while(i<n&&j<n)
        {
            if(a[i][j]=='Q')
                return 0;
            i++;
            j++;
        }
        i= x-1;
        j = y+1;
        while(i>=0&&j<n)
        {
            if(a[i][j]=='Q')
                return 0;
            i--;
            j++;
        }
        i = x+1;
        j= y-1;
        while(i<n&&j>=0)
        {
            if(a[i][j]=='Q')
                return 0;
            i++;
            j--;
        }
        
        return 1;
    }
    
    
    
    void call(vector<string> &b,int i,int &ans)
    {
        int n = b.size();
        if(i==n)
        {
            ans++;
            return ;
        }
        for(int j=0;j<n;j++)
        {
            if(isValid(b,i,j))
            {
                //cout<<i<<" "<<j<<endl;
                b[i][j] = 'Q';
                call(b,i+1,ans);
                b[i][j] = '.';
            }   
        }
        
        return ;
        
    }
    
    
    int totalNQueens(int n) {
        
        vector<string> b(n,string(n,'.'));
       // vector<vector<string>> ans;
        int ans =0;
        call(b,0,ans);
        return ans;
        
        
        
    }
};