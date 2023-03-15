class Solution {
public:
    int balancedStringSplit(string s) {
        
        // parameter
        int balanced = 0;
        int balanced_strings = 0;

        // start computing
        for (auto c: s) {

            if (c == 'L') balanced++;
            else balanced--;

            if (balanced == 0) balanced_strings++;

        }

        return balanced_strings;

    }
};
