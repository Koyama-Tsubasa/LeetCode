class Solution {
public:
    string removeDigit(string number, char digit) {
        
        // parameters
        std::string removed_MAX = "";
        int num_len = number.length();

        // start computing
        for (int i=0; i<num_len; i++) 
            if (number[i] == digit) {

                std::string temp_num = number.substr(0, i);
                if (i < num_len-1) temp_num += number.substr(i+1);
                removed_MAX = std::max(removed_MAX, temp_num);
               
            }

        return removed_MAX;

    }
};
