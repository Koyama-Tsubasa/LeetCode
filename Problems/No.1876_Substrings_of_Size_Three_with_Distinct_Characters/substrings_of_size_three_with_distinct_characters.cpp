class Solution {
public:
    int countGoodSubstrings(string s) {
        
        // parameters
        int count = 0;
        int duplicated = 0;
        std::vector<int> check_count(26, 0);

        // start computing
        if (s.length() < 3) return 0;
        else {

            for (int i=0; i<s.length(); i++) {

                int curr_alpha_ID = s[i] - 'a';
                check_count[curr_alpha_ID]++;
                if (check_count[curr_alpha_ID] == 2) duplicated++;

                if (i < 2) continue;
                else {

                    if (duplicated == 0) count++;

                    int start_of_curr_substring = s[i-2] - 'a';
                    check_count[start_of_curr_substring]--;
                    if (check_count[start_of_curr_substring] == 1) duplicated--;

                }

            }

            return count;

        }

    }
};
