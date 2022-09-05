// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int rnd40 = 7*(rand7()-1)+rand7()-1;
        while(rnd40>=40)
        {
            rnd40 = 7*(rand7()-1)+rand7()-1;
        }
        return rnd40%10+1;
    }
};