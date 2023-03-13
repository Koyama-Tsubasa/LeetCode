class Solution {
public:
    int minimumSum(int num) {
        
        // parameter
        std::vector<int> digits;

        // start computing
        for (int i=0; i<4; i++) {

            digits.push_back(num%10);
            num /= 10;

        }
        std::sort(digits.begin(), digits.end());
        
        return ((digits[0]+digits[1])*10 + digits[2] + digits[3]);

    }
};
