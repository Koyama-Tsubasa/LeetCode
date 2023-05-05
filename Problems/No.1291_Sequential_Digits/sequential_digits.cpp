class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
        // parameter
        std::vector<int> sequential_digits;

        // start computing
        std::string digits = "123456789";
        for (int iter=std::to_string(low).length(); iter<=std::to_string(high).length(); iter++) 
            for (int idx=0; idx<=9-iter; idx++) {

                int temp_digit = stoi(digits.substr(idx, iter));
                if ((low <= temp_digit) && (temp_digit <= high)) sequential_digits.push_back(temp_digit);
                else if (temp_digit < low) continue;
                else break;

            }

        return sequential_digits;

    }
};
