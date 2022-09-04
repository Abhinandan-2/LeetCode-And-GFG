class Solution {
public:
    int longestNiceSubarray(vector<int>& a) {
        
        int res =1;
        
        
        int g =-1;
        
        
        int  n = a.size();
        
        for(int k=0;k<n;k++)
        {
           
            for(int p=k-1;p>g;p--)
            {
               
                
                
                if((a[k]&a[p])!=0)
                {
                  
                    
                    g = p;
                    break;
                    
                    
                }
                
            }
          
            res = max(res,k-g);
            
        }
        
        
        
        return res;
        
        
    }
};