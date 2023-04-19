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

            std::string left_substr = longestNiceSubstring(s.substr(0, i));
            std::string right_substr = longestNiceSubstring(s.substr(i+1));

            return (left_substr.length() >= right_substr.length()) ? left_substr : right_substr;

        }

        return s;

    }
};
