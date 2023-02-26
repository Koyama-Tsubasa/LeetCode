class Solution {
public:
    int addDigits(int num) {
        
        // use Digit Root method
        if (num < 9) return num;
        else if (num%9 == 0) return 9;
        else return num%9;

    }
};
