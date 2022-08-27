class Solution {
public:
    vector<int> closestDivisors(int num) {

        int first = num+1;
        int second = num+2;
        
        int fS = sqrt(first),fF;
        int sS = sqrt(second),sF;
        
        while(first%fS!=0)
            fS--;
        while(second%sS!=0)
            sS--;
        
        fF = first/fS;
        sF = second/sS;
        
        if(abs(fF-fS)<abs(sF-sS))
            return {fF,fS};
        
        return {sF,sS};
        
    }
};