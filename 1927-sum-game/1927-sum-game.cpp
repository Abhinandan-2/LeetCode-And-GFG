class Solution {
public:
    bool sumGame(string a) {
        
        int n = a.size();
        int sumDiff, spaceDiff, leftSpace=0 ,rightSpace=0 ,leftSum=0, rightSum=0;
    
        for(int i=0;i<n;i++)
        {
            if(i<n/2)
            {
                if(a[i]!='?')
                    leftSum+=(a[i]-48);
                else
                    leftSpace++;
            }
            else
            {
                if(a[i]!='?')
                    rightSum+=(a[i]-48);
                else
                    rightSpace++;
            }
        }
        
        sumDiff = abs(leftSum-rightSum);
        spaceDiff = abs(leftSpace-rightSpace);
        
        if(leftSum>rightSum)
        {
            if(leftSpace>rightSpace)
                return true;
            else
            {
                if(spaceDiff%2==0)
                {
                    if(9*spaceDiff/2==sumDiff)
                        return false;
                    return true;
                }
                else
                    return true;
            }
        }
        else if(leftSum<rightSum)
        {
            if(leftSpace<rightSpace)
                return true;
            else
            {
                if(spaceDiff%2==0)
                {
                    if(9*spaceDiff/2==sumDiff)
                        return false;
                    return true;
                }
                else
                    return true;
            }
        }
        else
        {
            if(spaceDiff==0)
                return false;
            return true;
        }
        
        return false;
    }
};