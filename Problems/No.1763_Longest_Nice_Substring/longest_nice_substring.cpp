class Solution {
public:
    string longestNiceSubstring(string s) {
        
        // parameter
        std::unordered_set<char> buddies;

        // start computing
        // find buddies
        for (char &c: s) {

            if (std::islower(c)) buddies.insert(std::toupper(c));
            else buddies.insert(std::tolower(c));

        }

        // divide and conquer according to unfound buddies
        for (int i=0; i<s.length(); i++) {

            if (buddies.count(s[i])) continue;

            std::string left_substring = longestNiceSubstring(s.substr(0, i));
            std::string right_substring = longestNiceSubstring(s.substr(i+1));

            return (left_substring.length() >= right_substring.length()) ? left_substring : right_substring;

        }

        return s;

    }
};
