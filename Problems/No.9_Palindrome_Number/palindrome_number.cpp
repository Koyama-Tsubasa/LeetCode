class Solution {
public:
    bool isPalindrome(int x) {
        
        if ((x >= 0) and (x <= 9)) return true;     // if the digit number of x is 1
        else if (x<0 or x%10 == 0) return false;    // if x is negative or ten multiples
        else {
            long x_original = x;    // save the x
            long x_reverse = 0;     // calculate the reverse of x
            while (x_original!=0) {
                x_reverse = x_reverse*10 + x_original%10;
                x_original /= 10;
            }
            if (x == x_reverse) return true;
            else return false;
        }
        
    }
};
