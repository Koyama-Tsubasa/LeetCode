class Solution {
public:
    int numberOfSubstrings(string s) {
        
        // parameters
        int count = 0;
        int sLen = s.length();
        std::unordered_map<char, int> char_count = {{'a', 0}, {'b', 0}, {'c', 0}};

        // start computing
        int substr_start = 0;
        for (int substr_end=0; substr_end<sLen; substr_end++) {

            char_count[s[substr_end]]++;

            while ((char_count['a'] > 0) && (char_count['b'] > 0) && (char_count['c'] > 0) && 
                   (substr_start <= substr_end)) {

                char_count[s[substr_start++]]--;
                count += sLen - substr_end;
               
            }

        }

        return count;

    }
};
