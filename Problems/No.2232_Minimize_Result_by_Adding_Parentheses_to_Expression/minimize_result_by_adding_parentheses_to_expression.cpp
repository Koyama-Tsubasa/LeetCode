class Solution {
public:
    string minimizeResult(string expression) {
        
        // parameters
        int min_value = INT_MAX;
        int plus_idx = expression.find('+');
        std::string min_value_string = "";

        // start computing
        for (int left=0; left<plus_idx; left++) 
            for (int right=plus_idx+1; right<expression.length(); right++) {

                std::string V1 = expression.substr(0, left);
                std::string V2 = expression.substr(left, plus_idx-left);
                std::string V3 = expression.substr(plus_idx+1, right-plus_idx);
                std::string V4 = expression.substr(right+1);

                int temp_value = ((V1 == "") ? 1 : std::stoi(V1)) * 
                                  (std::stoi(V2) + std::stoi(V3)) * 
                                 ((V4 == "") ? 1 : std::stoi(V4));
                if (temp_value < min_value) {

                    min_value = temp_value;
                    min_value_string = V1 + "(" + V2 + "+" + V3 + ")" + V4;

                }

            }

        return min_value_string;

    }
};
