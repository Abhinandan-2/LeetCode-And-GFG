/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        
        
        int l =0 , h = n ,m,k;
        while(l<h)
        {
            m = l+(h-l)/2;
            k = guess(m);
            if(k==0)
                return m;
            if(k==-1)
            {
                h = m-1;
            }
            else
                l = m+1;
        }
        return l;
        
    }
};