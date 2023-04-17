class Solution {
public:
    int countGoodSubstrings(string s) {
        
        // parameters
        int count = 0;
        int duplicated = 0;
        std::unordered_map<char, int> check_count;

        // start computing
        if (s.length() < 3) return 0;
        else {

            for (int i=0; i<s.length(); i++) {

                check_count[s[i]]++;
                if (check_count[s[i]] == 2) duplicated++;

                if (i < 2) continue;
                else {

                    if (duplicated == 0) count++;

                    check_count[s[i-2]]--;
                    if (check_count[s[i-2]] == 1) duplicated--;

                }

            }

            return count;

        }

    }
};
