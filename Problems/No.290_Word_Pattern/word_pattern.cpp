class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        // parameters
        std::stringstream pString(s);
        std::unordered_map<char, string> pattern_matching;
        std::unordered_set<std::string> sCheck;
        std::vector<std::string> strings;
        std::string temp;

        // start computing
        while (pString >> temp) strings.push_back(temp);
        if (strings.size() != pattern.length()) return false;
        else {

            for (int i=0; i<pattern.size(); i++) {

                if (pattern_matching.find(pattern[i]) != pattern_matching.end()) { if (pattern_matching[pattern[i]] != strings[i]) return false; }
                else {

                    if (sCheck.count(strings[i]) > 0) return false;
                    else {

                        pattern_matching[pattern[i]] = strings[i];
                        sCheck.insert(strings[i]);

                    }

                }

            }

        }

        return true;

    }
};
