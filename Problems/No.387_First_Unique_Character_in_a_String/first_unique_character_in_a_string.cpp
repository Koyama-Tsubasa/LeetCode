class Solution {
public:
    int firstUniqChar(string s) {
        
        // parameter
        std::unordered_map<char, int> char_count;

        // start computing
        for (auto &c: s) char_count[c]++;
        for (int idx=0; idx<s.length(); idx++) 
            if (char_count[s[idx]] == 1) return idx;
        
        return -1;

    }
};
