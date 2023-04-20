class Solution {
public:
    int takeCharacters(string s, int k) {
        
        // parameters
        int minutes = INT_MAX;
        std::unordered_map<char, int> char_map;

        // start computing
        // calculate the total number of each character and check for the constraint
        for (auto &c: s) char_map[c]++;
        if ((char_map['a'] < k) || (char_map['b'] < k) || (char_map['c'] < k)) return -1;

        // traverse the string from left and right to find the minimum minutes
        int s_len = s.length();
        for (int left=0, right=0; left<s_len; left++) {

            while ((right <= s_len) && 
                   (char_map['a'] >= k) && (char_map['b'] >= k) && (char_map['c'] >= k)) {
                
                if (right < s_len) char_map[s[right]]--;
                right++;

            }
            minutes = std::min(minutes, left + (s_len-right) + 1);
            char_map[s[left]]++;

        }
        
        return minutes;

    }
};
