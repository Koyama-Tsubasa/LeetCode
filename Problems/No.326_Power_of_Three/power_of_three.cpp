class Solution {
public:
    bool isPowerOfThree(int n) {
        
        // start computing
        if (n <= 0) return false;
        else {

            double power = std::log10(n)/std::log10(3);
            if ((power - int(power)) == 0) return true;
            else return false;

        } 

    }
};
